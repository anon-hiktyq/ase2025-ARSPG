# from process_code import extract_func_def
import os
import re
import clang.cindex
from .main_class import *
from Convertor import SpecificationConvertor
from clang.cindex import Index, Config, CursorKind, TranslationUnit

clang.cindex.Config.set_library_path('/usr/lib/llvm-18/lib')
    

def create_required_type(global_type_info_dict):
    """
    生成需要插入到临时.c文件的typedef和非typedef的结构体
    """
    required_type_list = []
    for type_info in global_type_info_dict.values():
        required_type_list.append(type_info)
    required_type = '\n'.join(required_type_list)
    return required_type



def create_precondition(function_info: FunctionInfo) -> str:
    """
    生成需要插入到临时.c文件的precondition
    """
    with_list = []
    require_list = []
    syntax_str = ''
    value_str = ''
    def parse_parameters_assertion(parameter_list:[List[Parameter]], with_list:list[str], require_list:list[str], syntax_str:str, value_str:str):
        if not parameter_list:
            return '', f'Require emp\n'
        
        for parameter in parameter_list:
           
            print(parameter.name)
            # 获得 parameter_list 中的下一个 parameter
            



            # 是一个指针,非结构体,非数组参数
            
            if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                
                with_list.append(f'{value_str}{parameter.name}_v')
                if syntax_str != '' and value_str != '':
                    with_list.append(f'{value_str}{parameter.name}')
                access = '*' * parameter.ptr_depth
                require_list.append(
                                     f'{access}({syntax_str}{parameter.name}) == {value_str}{parameter.name}_v')
                
                if syntax_str != '' and value_str != '':
                    require_list.append(
                                        f'({syntax_str}{parameter.name}) == {value_str}{parameter.name}')
                continue
    

            # 是一个指针,结构体,非数组参数

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

                # 进入结构体的参数列表进行递归处理;
                parse_parameters_assertion(parameter.type.parameter_list, with_list, require_list, syntax_str, value_str)

                syntax_str =  old_syntax_str
                value_str = old_value_str
                
                continue

            # 是一个指针,非结构体,数组参数

            if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                
                #分别添加数组的数组符号,地址,长度
                if parameter.array_length == 'INT_MAX':

                    next_parameter = parameter_list[parameter_list.index(parameter) + 1]

                    with_list.append(f'{value_str}{parameter.name}_l')
                    require_list.append (f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)'
                                        )
                  
                    require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                    
                else:
                    with_list.append(f'{value_str}{parameter.name}_l')
                    require_list.append(f'store_int_array({syntax_str}{parameter.name},{value_str}{parameter.array_length}, {value_str}{parameter.name}_l)')
                    

                    for i in range(parameter.array_length):
                        with_list.append(f'{value_str}{parameter.name}_i')
                        require_list.append(f'a_l[{i}] == {value_str}{parameter.name}_i')

                continue

            #  是一个指针,结构体,数组参数
            if parameter.is_ptr and  parameter.is_struct and parameter.array_length != -1:
                raise ValueError(f'目前无法处理指针型结构体数组参数:{syntax_str}{parameter.name}')
           

            # 是一个非指针,结构体,非数组参数

            if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:

                old_syntax_str = syntax_str
                old_value_str = value_str
                
                syntax_str = syntax_str + parameter.name + '.'
                value_str = value_str + parameter.name + '_'
                # 进入结构体的参数列表进行递归处理;
                parse_parameters_assertion(parameter.type.parameter_list, with_list, require_list, syntax_str, value_str)
                syntax_str =  old_syntax_str
                value_str = old_value_str
                continue

            #目前只默认为int类型的数组
            # 是一个非指针,非结构体,数组参数
            if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                
                if parameter.array_length == 'INT_MAX':

                    next_parameter = parameter_list[parameter_list.index(parameter) + 1]

                    with_list.append(f'{value_str}{parameter.name}_l')
                    require_list.append (f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)'
                                        )
                    require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                    
                else:
                    with_list.append(f'{value_str}{parameter.name}_l')
                    require_list.append(f'store_int_array({syntax_str}{parameter.name},{parameter.array_length}, {value_str}{parameter.name}_l)')
                    
                    for i in range(parameter.array_length):
                        with_list.append(f'{value_str}{parameter.name}_{i}')
                        require_list.append(f'{value_str}{parameter.name}_l[{i}] == {value_str}{parameter.name}_{i}')

                continue

            # 是一个非指针,结构体,数组参数
            if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                raise ValueError(f'目前无法处理非指针型结构体数组参数:{syntax_str}{parameter.name}')

            # 是一个非指针,非结构体,非数组参数
            if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                if syntax_str != '' and value_str != '':
                    with_list.append(f'{value_str}{parameter.name}')
                    require_list.append(f'{syntax_str}{parameter.name} == {value_str}{parameter.name}')
                continue

            else:
                raise ValueError(f'遇到了意料之外的数据类型:{syntax_str}{parameter.name}')

        if with_list != []:
            with_str = 'With ' + ' '.join(with_list)
        else: 
            with_str = ''
        
        if require_list != []:
            require_str = 'Require ' + ' && '.join(require_list)
        else:
            require_str = 'Require emp'

        
        return with_str, require_str
    
    with_str, require_str = parse_parameters_assertion(function_info.parameter_list, with_list, require_list, syntax_str, value_str) 
    
    if function_info.func_type == 'void':
        ensure_str = 'Ensure emp'
    else:
        ensure_str = 'Ensure Results(__return)'

    return f'/*@\n{with_str}\n{require_str}\n{ensure_str}\n*/'



def create_c_file(directory: str, filename: str, content: str) -> None:
    """
    在指定目录中创建一个新的 .c 文件，并写入给定的内容。
    :param directory: 目标目录的路径
    :param filename: 文件名（不包括路径）
    :param content: 要写入文件的内容
    """
    # 确保目录存在，如果不存在则创建
    if not os.path.exists(directory):
        os.makedirs(directory)
        print(f"目录 {directory} 已创建。")

    # 构建完整的文件路径
    file_path = os.path.join(directory, filename)

    # 打开文件并写入内容
    try:
        with open(file_path, 'w') as f:
            f.write(content)
        print(f"文件 {file_path} 已成功创建并写入。")
    except Exception as e:
        print(f"创建文件时出错: {e}")

def create_annotated_callee(callee_set: set, function_info_list: List[FunctionInfo],loop_path) -> str:
    if len(callee_set) == 0:
        return ''
    annotated_callee_list = []
    for callee_name in callee_set:
        for function_info in function_info_list:
            if function_info.name == callee_name:


                function_header = function_info.code.split('{')[0]
                # 提取新的函数
           
                file_path = f"{loop_path}/{callee_name}.c"
                #function_info.code = extract_function(file_path,callee_name)[0][2]
                #code = function_info.code 
                # print(function_info)
                # print(extract_function(file_path,function_info))
                code = extract_function(file_path,function_info)[0][2]

               

                group = code.split('{')
                function_code = '{'.join(group[1:])
                annotated_callee = f'\n{function_header}{function_info.annotation}\n{{{function_code}'
                # function_info.code = annotated_callee 
                annotated_callee_list.append(annotated_callee)
                break
    
    return '\n'.join(annotated_callee_list)

# def get_annotated_callee(callee_set: set, function_info_list: List[FunctionInfo]) -> str:
#     if len(callee_set) == 0:
#         return ''
#     annotated_callee_list = []
#     for callee_name in callee_set:
#         for function_info in function_info_list:
#             if function_info.name == callee_name:
#                 annotated_callee = function_info.code
#                 annotated_callee_list.append(annotated_callee)
#                 break
    
#     return '\n'.join(annotated_callee_list)

def create_callee_specifications(callee_set: set, function_info_list: List[FunctionInfo],loop_path) -> str:

    if len(callee_set) == 0:
        return ''
    annotated_callee_list = []
    for callee_name in callee_set:
        for function_info in function_info_list:
            if function_info.name == callee_name:


                function_header = function_info.code.split('{')[0]
                # 提取新的函数

                annotation = function_info.specification
           
                file_path = f"{loop_path}/{callee_name}.c"
                #function_info.code = extract_function(file_path,callee_name)[0][2]
                #code = function_info.code 
                code = extract_function(file_path,function_info)[0][2]

               

                group = code.split('{')
                function_code = '{'.join(group[1:])
                annotated_callee = f'\n{annotation}\n{function_header}\n{{{function_code}'
                # function_info.code = annotated_callee 
                annotated_callee_list.append(annotated_callee)
                break
    
    return '\n'.join(annotated_callee_list)

def create_callee_specifications_by_llm(callee_set: set, function_info_list: List[FunctionInfo],loop_path) -> str:

    if len(callee_set) == 0:
        return ''
    annotated_callee_list = []
    for callee_name in callee_set:
        for function_info in function_info_list:
            if function_info.name == callee_name:

                
                
                file_path = f"{loop_path}/{callee_name}.c"

                code = ''

                with open(file_path, "r", encoding="utf-8") as file:
                    code = file.read()
                
                
                # function_info.code = annotated_callee 
                annotated_callee_list.append(code)
                break
    
    return '\n'.join(annotated_callee_list)

def extract_function(file_path: str, func: FunctionInfo) -> List[Tuple[int, int, str]]:

    result = []

    # 校验文件存在性
    if not os.path.isfile(file_path):
        result.append((0,0,func.code))
        return result
        # raise FileNotFoundError(f"文件不存在: {file_path}")
    
  
    # 解析源码
    index = Index.create()
    try:
        tu = index.parse(file_path, options=TranslationUnit.PARSE_DETAILED_PROCESSING_RECORD)
    except Exception as e:
        raise RuntimeError(f"解析文件失败: {str(e)}")
    
    # 提取函数定义
   
    
    def visitor(cursor):
        if cursor.kind in (CursorKind.FUNCTION_DECL, CursorKind.CXX_METHOD):
            if cursor.spelling == func.name and cursor.is_definition():
                start = cursor.extent.start
                end = cursor.extent.end
                
                with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                    lines = f.readlines()
                
                code = ''.join(lines[start.line-1:end.line])
                result.append((
                    start.line, 
                    end.line,   
                    code.strip()
                ))
                
        for child in cursor.get_children():
            visitor(child)
    
    visitor(tu.cursor)
    return result

def create_generated_c_file(function_info: FunctionInfo,output_path: str):
    print(f'ACSL {function_info.name}.c文件的内容为{function_info.code}')
    create_c_file(output_path, f'{function_info.name}.c',function_info.code)

   


def create_annotated_c_file(function_info: FunctionInfo, function_info_list: list[FunctionInfo], output_path: str, loop_path:str,
                            global_type_info_dict):
    
    def remove_comments_regex(code_str):
        # 移除单行注释（//@或#@形式）
        code_str = re.sub(r'//@.*', '', code_str)
        # 移除多行注释（/*@ ... */）
        code_str = re.sub(r'/\*@[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
        # 移除标准多行注释（/* ... */）[3,4](@ref)
        code_str = re.sub(r'/\*[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
        return code_str
    

    
    required_type = create_required_type(global_type_info_dict)
    

    annotated_callee_str = create_annotated_callee(function_info.callee_set, function_info_list, loop_path)
    
    function_info.annotation = create_precondition(function_info)

    headers = '''
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    '''
    code = remove_comments_regex(function_info.code)
    groups = code.split('{')

    content = (headers +
               f'{required_type}\n' + annotated_callee_str +
               f'\n{groups[0]}\n{function_info.annotation}' + '{' + "{".join(groups[1:]))
    
    print(f'预注释{function_info.name}.c文件的内容为{content}')
    create_c_file(output_path, f'{function_info.name}.c', content)
    create_c_file(loop_path, f'{function_info.name}.c', content)

    



def create_final_c_file(function_info: FunctionInfo, function_info_list: list[FunctionInfo], loop_path:str,
                            global_type_info_dict):


    required_type = create_required_type(global_type_info_dict)


    annotated_callee_str = create_annotated_callee(function_info.callee_set, function_info_list,loop_path)


    headers = '''
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    '''
    
    function_header = function_info.code.split('{')[0]
           
    file_path = f"{loop_path}/{function_info.name}.c"
                
    code = extract_function(file_path,function_info)[0][2]

    groups = code.split('{')

    content = (headers +
               f'{required_type}\n' + annotated_callee_str +
               f'\n{function_header}\n{function_info.annotation}\n' + '{' + "{".join(groups[1:]))
    
    print(f'完整注释{function_info.name}.c 文件的内容为{content}')
    create_c_file(loop_path, f'{function_info.name}.c', content)


def create_specification(function_info: FunctionInfo, function_info_list: list[FunctionInfo], output_path:str,loop_path:str,
                            global_type_info_dict):
    

        required_type = create_required_type(global_type_info_dict)

        annotated_callee_str = create_callee_specifications(function_info.callee_set, function_info_list ,loop_path)
        
        function_header = function_info.code.split('{')[0]
            
        file_path = f"{loop_path}/{function_info.name}.c"

        convertor = SpecificationConvertor(function_info)

        function_info.specification = convertor.inconvert_annotations(function_info.annotation)

                    
        code = extract_function(file_path,function_info)[0][2]

        groups = code.split('{')

        content = (
                f'{required_type}\n' + annotated_callee_str +
                f'\n{function_info.specification}\n{function_header}\n' + '{' + "{".join(groups[1:]))
        
        print(f'{function_info.name}.c 的规约的内容为{content}')
        create_c_file(output_path, f'{function_info.name}.c', content)


    
        

def create_specification_by_llm(function_info: FunctionInfo, function_info_list: list[FunctionInfo], input_path,output_path,global_type_info_dict):

    required_type = create_required_type(global_type_info_dict)

    annotated_callee_str = create_callee_specifications_by_llm(function_info.callee_set, function_info_list ,output_path)
    
    
    input_path =  f"{input_path}/{function_info.name}.c"
    
    code = extract_function(input_path,function_info)[0][2]

    print(function_info)
    
    convertor = SpecificationConvertor(function_info)

    if 'test' in function_info.name:
        content = (
                    f'{required_type}\n' + annotated_callee_str +
                    f'{code}'
                )

        create_c_file(output_path, f'{function_info.name}.c', content)
        return 


    if function_info.parameter_list == [] and function_info.func_type == 'void':
        content = (
                f'{required_type}\n' + annotated_callee_str +
                f'\n{code}'
            )
    elif function_info.func_type == 'void':
        

        template = f'''/*@
    ensures PLACE_HOLDER;
    */
    '''

        content = (
                    f'{required_type}\n' + annotated_callee_str +
                    f'{template}\n{code}'
                )
        
        print(content)

       
        content = convertor.specgen_annotations(content)

    else:

        
        
        template = f'''/*@
    ensures PLACE_HOLDER;
    ensures \\result == PLACE_HOLDER;
    */
    '''

        content = (
                    f'{required_type}\n' + annotated_callee_str +
                    f'{template}\n{code}'
                )
        
        print(content)

       
        content = convertor.specgen_annotations(content)



    create_c_file(output_path, f'{function_info.name}.c', content)

    print(f'{function_info.name}.c 的规约的内容为{content}')

    
    