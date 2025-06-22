import openai
import re
from SpecAutoAnnotator.main_class import *


class SpecificationConvertor:

    def __init__(self,function_info: FunctionInfo = None):
        # OpenAI 客户端初始化
        # self.llm ='gpt-3.5-turbo'
        # self.llm ='claude-3-7-sonnet'
        # self.llm = 'deepseek-v3'
        # self.llm = 'claude-3-7-sonnet-thinking'
        self.llm ='gpt-4o'
        self.function_info = function_info
        self.vars_list = self.create_flatten_vars()
        self.vars_map = self.create_vars_map()

       
        
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-hfyQZDWdgyc4oQnDw4nvOh6KT1iDQ5EbNy9UjQwnMzBntefe"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]



    def extract_var_map_from_file(self,condition):

        # 根据 || 分割条件表达式
        # sub_conditions = [s.strip().strip('()') for s in condition.split("||")]

        def remove_outer_parentheses(s):
            s = s.strip()
            if len(s) >=2 and s[0] == '(' and s[-1] == ')':
                return s[1:-1]
            else:
                return s

        def split_conditions(condition):
            # 按括号外的 "||" 分割
            sub_conditions = re.split(r'\|\|(?![^(]*\))', condition)
            # 去掉每部分的首尾空格和括号
            return [remove_outer_parentheses(s) for s in sub_conditions]
        
        sub_conditions = split_conditions(condition)

        # 存储所有 var_map 的列表
        var_maps = []
        path_conds = []
        results = []

        def split_path_and_state(expression):

            if '&&' not in expression:

                if '__return' not in expression:
                    # state
                    path = None
                    result = None
                    state = expression.strip()
                else :
                    # result
                    path = None
                    result = expression.strip()
                    state = None

            else: 
                parts = expression.split('&&')
                
                if '__return' not in parts[-1]:
                    state = parts[-1]
                    path_parts = []
                    result_parts = []
                    path_flag = 1
                    for part in parts [:-1]:
                        if '__return' not in part and path_flag:
                            path_parts.append(part)
                        else:
                            path_flag = 0
                            result_parts.append(part)
                    
                    if path_parts == []:
                        path =None
                    else:
                        path = '&&'.join(path_parts)

                    if result_parts == []:
                        result =None
                    else:
                        result = '&&'.join(result_parts)
                
                else:
                    state = None
                    path_parts = []
                    result_parts = []
                    path_flag = 1
                    for part in parts:
                        if '__return' not in part and path_flag:
                            path_parts.append(part)
                        else:
                            path_flag = 0
                            result_parts.append(part)
                    
                    if path_parts == []:
                        path =None
                    else:
                        path = '&&'.join(path_parts)

                    if result_parts == []:
                        result =None
                    else:
                        result = '&&'.join(result_parts)

            return path, state,result
            
 
        
        def fix_brackets(s: str) -> str:
            stack = []
            to_remove = set()  # 记录需要删除的多余括号位置
            bracket_pairs = {')': '(', ']': '[', '}': '{'}
            
            # 第一次遍历：检查括号合法性并标记多余括号
            for i, char in enumerate(s):
                if char in bracket_pairs.values():  # 左括号入栈
                    stack.append((char, i))
                elif char in bracket_pairs:        # 右括号尝试匹配
                    if stack and stack[-1][0] == bracket_pairs[char]:
                        stack.pop()  # 匹配成功，弹出左括号
                    else:
                        to_remove.add(i)  # 多余右括号，标记删除
            
            # 标记未匹配的左括号（需要补右括号）
            missing_right = [i for _, i in stack]
            
            # 第二次遍历：修复字符串
            result = []
            for i, char in enumerate(s):
                if i not in to_remove:  # 保留非多余括号
                    result.append(char)
            
            # 补全缺失的右括号（按左括号出现顺序反向补全）
            for i in sorted(missing_right, reverse=True):
                # 在左括号后插入对应的右括号
                pos = i + 1
                right_bracket = {v: k for k, v in bracket_pairs.items()}[s[i]]
                result.insert(pos, right_bracket)
            
            return ''.join(result).strip()

        def parse_expressions(s):

            # (a==0)*(b==(1*2))*(...)
            # 不在 () 里 * 是 分隔符，在 () 里的是 乘
            # a == 1 * 5 需要特判
            
            if s.count('==') == 1:
                s = f'({s})'
            var_map = {}
            remaining = s.strip()
            stack = []
            expr_start = 0
            i = 0
            n = len(remaining)
            
            while i < n:
                char = remaining[i]
                
                # 处理括号层级
                if char == '(':
                    stack.append(i)
                elif char == ')':
                    if stack:
                        stack.pop()
                
                # 遇到逻辑运算符且不在括号内时，分割表达式
                if i < n-1 and remaining[i:i+2] in ('&&', '* ') and not stack:
                    # 提取当前表达式
                    expr = remaining[expr_start:i].strip()
                    # 解析表达式中的键值对
                    eq_pos = expr.find('==')
                    if eq_pos != -1:

                        var = expr[:eq_pos].strip(' ()')
                        
                        
                        value = fix_brackets(expr[eq_pos+2:])
              

                        var_map[var] = value
                    expr_start = i + 2
                    i += 1  # 跳过运算符的第二个字符
                
                i += 1
            
            # 处理最后一个表达式
            expr = remaining[expr_start:].strip()
            eq_pos = expr.find('==')
            if eq_pos != -1:

                var =expr[:eq_pos].strip(' ()')
    
                value = fix_brackets(expr[eq_pos+2:])
       
                var_map[var] = value
                
            return var_map
        
       
        
        for sub_condition in sub_conditions:

                path,state,result = split_path_and_state(sub_condition)
                
                path_cond = path
                path_conds.append(path_cond)
                
                var_map = None  # 为每个子条件创建一个新的 var_map

                if state:
                    var_map = parse_expressions(state)

                var_maps.append(var_map)  # 将 var_map 添加到列表中

                results.append(result)


        

        return var_maps,path_conds,results

    def create_require_str(self) -> str:
        """
        生成需要插入到临时.c文件的precondition
        """
        require_list = []
        ptr_list =[]
        syntax_str =''
       
        def parse_parameters_assertion(parameter_list:[List[Parameter]],require_list:list[str],ptr_list:list[str],syntax_str:str):
            if not parameter_list:
                return None
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    require_list.append(rf'\valid({syntax_str}{parameter.name})')
                    ptr_list.append(f'{syntax_str}{parameter.name}')

                    old_syntax_str = syntax_str
                                   
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'

                    syntax_str = syntax_str + access_name + '->'
                    
                    parse_parameters_assertion(parameter.type.parameter_list, require_list ,ptr_list, syntax_str)
                    
                    syntax_str = old_syntax_str
                    continue

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    require_list.append(rf'\valid({syntax_str}{parameter.name})')
                    ptr_list.append(f'{syntax_str}{parameter.name}')

                    if parameter.array_length == 'INT_MAX':

                        next_parameter = parameter_list[parameter_list.index(parameter) + 1]
                        require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')

                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    
                    require_list.append(rf'\valid({syntax_str}{parameter.name})')
                    ptr_list.append(f'{syntax_str}{parameter.name}')
                    
                    continue
        
            if require_list == []:
                require_str = None
            else:
                require = " && ".join(require_list)
                require_str = f' requires {require} ;'   
            
            if ptr_list != []:
                ptr_str = ','.join(ptr_list)
                require_str += f'\n requires \separated({ptr_str}) ;'
            
            return require_str
        
        return parse_parameters_assertion(self.function_info.parameter_list,require_list,ptr_list,syntax_str) 


    def create_exists_str(self) -> str:
        """
        生成需要插入到临时.c文件的precondition
        """
        require_list = []
        exists_list =[]
        syntax_str = ''
        value_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]],require_list:list[str], exists_list:list[str] , syntax_str:str, value_str:str):
            if not parameter_list:
                return None
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                
                
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'

                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    
                    parse_parameters_assertion(parameter.type.parameter_list, require_list ,exists_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                #目前作为数组处理,等待后续使用clang进行分析再改进
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    if parameter.array_length == 'INT_MAX':
                        next_parameter = parameter_list[parameter_list.index(parameter) + 1]
                        require_list.extend([f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)',
                                            ])
                        exists_list.append(f'{value_str}{parameter.name}_l')
                        require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                    else:
                        require_list.extend([f'store_int_array({syntax_str}{parameter.name},{value_str}{parameter.array_length}, {value_str}{parameter.name}_l)',
                                            ])
                        exists_list.append(f'{value_str}{parameter.name}_l')

                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                   
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                
                
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'

                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list,require_list,exists_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为int类型的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    require_list.append(f'store_int_array({syntax_str}{parameter.name}, {parameter.array_length}, {value_str}{parameter.name}_l)')
                    exists_list.append(f'{value_str}{parameter.name}_l')
                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据类型:{syntax_str}{parameter.name}')

            
            if exists_list == []:
                return None

            exists_str = f''' exists  {' '.join(exists_list)},    
    {' && '.join(require_list)} &&
    '''     
            
            return exists_str
        
        return parse_parameters_assertion(self.function_info.parameter_list,require_list, exists_list, syntax_str, value_str) 
    
    def create_vars_map(self):
        vars_map = []
        value_str = ''
        syntax_str = ''
        vars_map.append(('result',r'\result'))
        def parse_parameters_assertion(parameter_list:[List[Parameter]],vars_map, syntax_str :str,value_str:str):
            if not parameter_list:
                return None
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:


                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'


                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_map, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    access = '*' * (parameter.ptr_depth)

                    vars_map.append((rf'{access}\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}_v'))
                    vars_map.append((rf'\old({access}{syntax_str}{parameter.name})',f'{value_str}{parameter.name}_old_v'))
                    vars_map.append((rf'{access}{syntax_str}{parameter.name}',f'{value_str}{parameter.name}_v'))
                    
                    if value_str != '' and syntax_str != '':

                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))

                    
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                   
                    if parameter.array_length != 'INT_MAX':
                        for i in range(parameter.array_length):
                        
                            vars_map.append((rf'\old({syntax_str}{parameter.name}[{i}])',f'old_{value_str}{parameter.name}_{i}'))
                            vars_map.append((rf'{syntax_str}{parameter.name}[{i}]',f'{value_str}{parameter.name}_{i}'))
                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    

                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))

                    old_syntax_str = syntax_str
                    old_value_str = value_str


                    syntax_str = syntax_str +  parameter.name + '.'
                    value_str = value_str + parameter.name + '_'


                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_map,  syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为int类型的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                   
                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                  
                    
                    for i in range(parameter.array_length):
                        
                        vars_map.append((rf'\old({syntax_str}{parameter.name}[{i}])',f'old_{value_str}{parameter.name}_{i}'))
                        vars_map.append((f'{syntax_str}{parameter.name}[{i}]',f'{value_str}{parameter.name}_{i}'))
                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if value_str != '' and syntax_str != '':
                       
                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))


                    else:

                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                    
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据类型:{syntax_str}{parameter.name}')

            
           
            return vars_map
        
        return parse_parameters_assertion(self.function_info.parameter_list,vars_map, syntax_str ,value_str) 

    def create_flatten_vars(self):
        vars_list =[]
        value_str = ''
        syntax_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]],vars_list, syntax_str :str,value_str:str):
            if not parameter_list:
                return None
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:


                   
                    vars_list.append((f'{value_str}{parameter.name}','110',f'{syntax_str}{parameter.name}'))

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'


                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    access = '*' * (parameter.ptr_depth)


                    vars_list.append((f'{value_str}{parameter.name}_v','100',rf'\\old({access}{syntax_str}{parameter.name})'))
                    
                    if value_str != '' and syntax_str != '':
                        
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\old({syntax_str}{parameter.name})'))
                    
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    vars_list.append((f'{value_str}{parameter.name}','101',f'{syntax_str}{parameter.name}'))

                   
                    if parameter.array_length != 'INT_MAX':
                        for i in range(parameter.array_length):
                            vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\old({syntax_str}{parameter.name}[{i}])'))

                          
                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    vars_list.append((f'{value_str}{parameter.name}','010',f'{syntax_str}{parameter.name}'))

                    old_syntax_str = syntax_str
                    old_value_str = value_str


                    syntax_str = syntax_str +  parameter.name + '.'
                    value_str = value_str + parameter.name + '_'


                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list,  syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为int类型的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    vars_list.append((f'{value_str}{parameter.name}','001',f'{syntax_str}{parameter.name}'))

                    for i in range(parameter.array_length):
                        vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\old({syntax_str}{parameter.name}[{i}])'))

                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if value_str != '' and syntax_str != '':
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\old({syntax_str}{parameter.name})'))

                    else:
                        vars_list.append((f'{value_str}{parameter.name}','000',f'{syntax_str}{parameter.name}'))      
                    
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据类型:{syntax_str}{parameter.name}')

            
           
            return vars_list
        
        return parse_parameters_assertion(self.function_info.parameter_list,vars_list, syntax_str ,value_str) 







    def convert_annotations(self, annotations):

        # print (annotations)


        if self.function_info:
            exists_str = self.create_exists_str()
            
        else:
            exists_str = None


        index = annotations.find("*/")
        if index != -1:
            before = annotations[:index + 2]  # 包含 '*/'
            after = annotations[index + 2:]
        
        def replace_at(match):
            variable = match.group(1).strip()
            return f"{variable}@pre"
        
        def replace_forall(match):
            variable = match.group(1).strip()
            return f"forall ({variable}:Z),"
    
        def replace_exists(match):
            variable = match.group(1).strip()
            return f"exists ({variable}:Z),"


        parts = before.strip()[3:-2].split('loop invariant')
        invariants = [f'({part.strip()})' for part in parts if part.strip()]
        invariant = ' &&\n'.join(invariants)
        invariant = re.sub(r'\\forall\s+(?:int|integer)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*;' , replace_forall, invariant)
        invariant = re.sub(r'\\exists\s+(?:int|integer)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*;' , replace_exists, invariant)
        invariant = re.sub(r'\\at\(\s*([a-zA-Z0-9_\[\]\->\.\*]+)\s*,\s*Pre\s*\)', replace_at, invariant)
        invariant = re.sub(r'([a-zA-Z_][a-zA-Z0-9_]*)\[', r'\1_l[', invariant)
        invariant = re.sub(r'(<|<=)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s+(<|<=)', r'\1 \2 && \2 \3', invariant)
        invariant = invariant.replace("==>", "=>")
        invariant = invariant.replace(';','')

        if exists_str:
            before = f'''/*@ Inv
    {exists_str.strip()}
    {invariant}
    */
    ''' 
        else:
            before = f'''/*@ Inv
    {invariant}
    */
    ''' 

        return before+after
    

    def inconvert_annotations(self, annotations):


        def updated_condition_str(condition_str, predefined_vars):
            # 定义需要排除的关键字和量词
            EXCLUDED_KEYWORDS = {'exists', 'forall','__return','store_int_array'}
            
            # 严格变量正则（匹配标准变量名）
            variable_pattern = r'(?<!\w)([a-zA-Z_]\w*)(?!\w)'
            
            # 提取所有候选变量
            candidates = set(re.findall(variable_pattern, condition_str))
            
            # 多级过滤
            new_vars = []
            for var in candidates:
                if (var not in predefined_vars and               # 不在预定义集合中
                    var.lower() not in EXCLUDED_KEYWORDS and     # 不是关键字
                    not var.lstrip('-').isdigit() and            # 不是数字
                    not any(op in var for op in {'+', '-', '*', '/', '%'})  # 不含操作符
                ):
                    new_vars.append(var)
            
            new_vars = sorted(new_vars)

            # 将新变量添加到exists声明中
            if not new_vars:
                    return condition_str
            
                # 在exists后追加新变量
            if 'exists' in condition_str:
                    # 提取已存在的变量
                    exists_part = condition_str.split('exists')[1].split(',')[0]
                    existing_vars = [v.strip() for v in exists_part.split() if v.strip()]
                
                    
                    # 添加新变量（不重复）
                    vars_to_add = [v for v in new_vars if v not in existing_vars]
                    if vars_to_add:
                        # 在第一个exists后插入新变量
                        parts = condition_str.split('exists', 1)
                        
                        updated_str = f"{parts[0]}exists {' '.join(vars_to_add)}{parts[1]}"
                    else:
                        updated_str = condition_str
            else:
                    updated_str = f"exists {' '.join(new_vars)}, {condition_str}"
                
            
            return updated_str


        flatten_vars = self.vars_list

        ensure = annotations.split('Ensure') [-1][:-2].strip()

       

        ensure_list=[]
        array_names = []
        var_names = []

        if flatten_vars:
            for vars in flatten_vars:
                var_names.append(vars[0])
                if vars[1] == '101':
                    array_names.append(f'{vars[0]}_l')
        
        ensures = ensure.split('||')
        updated_ensures = []
        for part in ensures:

            if 'exists' in ensure:
                part = updated_condition_str(part ,var_names)

            updated_ensures.append(part)
        
        ensure ='||'.join(updated_ensures)
            

        var_maps,path_conds,results = self.extract_var_map_from_file(ensure)
       

        for var_map, path_cond, result in zip(var_maps, path_conds, results):
        
            print(f"Variable Map: {var_map}")
            print(f"Path Condition: {path_cond}")
            print(f"Result: {result}")

           
            def fix_brackets(s: str) -> str:
                stack = []
                to_remove = set()  # 记录需要删除的多余括号位置
                bracket_pairs = {')': '(', ']': '[', '}': '{'}
                left_to_right = {'(': ')', '[': ']', '{': '}'}

                # 第一次遍历：检查括号合法性并标记多余括号
                for i, char in enumerate(s):
                    if char in bracket_pairs.values():  # 左括号入栈
                        stack.append((char, i))
                    elif char in bracket_pairs:        # 右括号尝试匹配
                        if stack and stack[-1][0] == bracket_pairs[char]:
                            stack.pop()  # 匹配成功，弹出左括号
                        else:
                            to_remove.add(i)  # 多余右括号，标记删除

                # 收集所有未匹配的左括号（需要补右括号）
                missing_right = [left_to_right[char] for char, _ in stack]

                # 第二次遍历：构造修复后的字符串
                result = []
                for i, char in enumerate(s):
                    if i not in to_remove:  # 保留合法字符
                        result.append(char)

                # 贪心补全右括号：统一追加到末尾
                result.extend(missing_right)

                return ''.join(result).strip()

            if path_cond:
                path_cond = fix_brackets(path_cond)
            if result:
                result =  fix_brackets(result)
            
            
            # state_list =[]
       
            # for key in var_map:
            #     state_list.append(f'{key} == {var_map[key]}')

            #     state = '&&'.join(state_list)



            def replace_quantifier(match):
                quantifier = match.group(1).strip()  # exists 或 forall
                variables = match.group(2).strip().split()  # 变量列表（如 ["a", "b", "c"]）
                # 去掉 variables中的以 array_names 中的任一项开头的
                variables = [var for var in variables if not any(var.startswith(array_name) for array_name in array_names)]
                # 格式化为 "\quantifier int var1, var2;"
                # 如果 variables 为空, 则返回去掉量词匹配部分的剩余部分
                if not variables:
                    return ''
                return f"\\{quantifier} int {', '.join(variables)}; "

            # 正则表达式匹配 exists/forall 后的所有变量直到逗号或行尾
            pattern = r"(exists|forall)\s+([a-zA-Z_@][\w@]*(?:\s+[a-zA-Z_@][\w@]*)*)\s*,?"

           

            state = None
            state_list =[]
            if var_map:
                for key in var_map:
                    state_list.append(f'{key} == {var_map[key]}')
                    if state_list:
                        state = '&&'.join(state_list)
            
            if path_cond:
                path_cond = re.sub(pattern, replace_quantifier, path_cond)

            if state:
                state = re.sub(pattern, replace_quantifier, state)

            


            # if path_cond and 'exists' in path_cond:
            #     if state:
            #         state = f'{path_cond} => {state}'
            #         path_cond = None
                
            


            # 把基于存在量词和逻辑变量的数组表示转为直接表示


            if flatten_vars:
                # print(flatten_vars)

                for vars in flatten_vars:


                    # var@pre <- \old(var)
                    if state :
                        state = state.replace(f'{vars[0]}@pre',f'\old({vars[0]})')
                    if result :
                        result = result.replace(f'{vars[0]}@pre',f'\old({vars[0]})')    
                    if path_cond : 
                        path_cond = path_cond.replace(f'{vars[0]}@pre',f'\old({vars[0]})') 

                    
                    # 000
                    # x 为整数, p 为结构体指针  p_x <- \old(p->x)
                    # p_q_x <- \old(p->q->x)

                    # 100
                    # 指针 p_v <- *(\old(p)) 
                    # 嵌套指针 p_x_v <- *(\old(p->x))
                    # 多层指针 p_v <- **(\old(p)) 
                    if vars[1]== '100' or '000' : 

                        replacement = vars[2]
                        
                        # 定义替换函数（确保完整变量匹配）
                        def replace_var(text, var, replacement):
                            # 使用正则匹配单词边界（避免替换 "xx" 里的 "x"）
                            pattern = re.compile(r'\b' + re.escape(var) + r'\b')
                            return pattern.sub(replacement, text)

                        # 执行替换
                        if state:
                            state = replace_var(state, vars[0], replacement)
                        if result:
                            result = replace_var(result, vars[0], replacement)
                        if path_cond:
                            path_cond = replace_var(path_cond, vars[0], replacement)


                    if vars[1] == '101' or '001':

                        logic_var = f'{vars[0]}_l'
                        logic_var_pattern = re.compile(rf'\b{re.escape(logic_var)}(?:_\d+)?\b')  

                        def replace_logic_var(text):
                            return logic_var_pattern.sub(vars[2], text)

                        if state:
                            state = replace_logic_var(state)
                        if result:
                            result = replace_logic_var(result)
                        if path_cond:
                            path_cond = replace_logic_var(path_cond)

                    
                
            
            # 如果 state 中有 __return, 其实是 result， 此时没有 state
            # state = state.replace('__return','\\result')
            # state = state.replace('=>','==>')


            if state:
                state = state.replace('__return','\\result')
                state = state.replace('=>','==>')

            if result :
                result = result.replace('__return','\\result')
                result = result.replace('=>','==>')


            if path_cond :
                path_cond = path_cond.replace('__return','\\result')
                path_cond = path_cond.replace('=>','==>')
            

            if path_cond != None and result !=None and state!=None:
                ensure_item = f'''
ensures {path_cond} ==> {state};
ensures {path_cond} ==> {result};
'''
            elif path_cond != None and state!=None:
                ensure_item = f'''
ensures {path_cond} ==> {state};
'''         
            elif result !=None and state!=None:
                ensure_item = f'''
ensures {state};
ensures {result};
'''         
            elif path_cond != None and result!=None:
                ensure_item = f'''
ensures {path_cond} ==> {result};
'''      

            elif state!=None: 
                ensure_item = f'''
ensures {state};
'''
            elif result!=None: 
                ensure_item = f'''
ensures {result};
'''         
            else :
                ensure_item = str()

            ensure_list.append(ensure_item)

        ensure_str = ''.join(ensure_list)
        


        require_str = self.create_require_str()

        if require_str and ensure_str:
            annotations = f'''/*@
{require_str}
{ensure_str}
*/
'''
        elif ensure_str:
            annotations = f'''/*@
{ensure_str}
*/
'''
        else:
            annotations = ''
        return annotations


            
    def specgen_annotations(self, annotations):

            """调用大模型生成ACSL规约"""

            prompt =  self.get_specgen_prompt(annotations)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                # 将内容添加到消息中
                self.messages.append({"role": "user", "content": prompt})
            
                # 获取助手的响应
                response = self.client.chat.completions.create(
                    model= self.llm,
                    messages=self.messages,
                    temperature=0.3
                )

                def extract_last_c_code(text):
                    # 匹配 C 代码块（Markdown 代码块 或 以 #include 开头的代码）
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown 代码块

                    return code_blocks[-1] if code_blocks else text  # 返回最后一个 C 代码块

                # 处理响应
                assistant_response = response.choices[0].message.content
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                print(f"API调用失败: {e}")
                return None

    
    
    def get_specgen_prompt(self,annotations):
         # 从文件中读取 prompt 模板
        with open("prompt/specgen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        specgen_prompt = prompt_template.format(code = annotations)

        return specgen_prompt

    
if __name__ == "__main__":
   conv = SpecificationConvertor()

   input = r'''
    /*@
      loop invariant (1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (1 <= i <= n && \forall integer j; 0 <= j < i ==> max >= a[j]));
      loop invariant (1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (1 <= i <= n && \forall integer j; 0 <= j < i ==> max >= a[j]));
      loop invariant (!(1 < \at(n, Pre))) ==> ((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */

'''
   print(conv.convert_annotations_(input))