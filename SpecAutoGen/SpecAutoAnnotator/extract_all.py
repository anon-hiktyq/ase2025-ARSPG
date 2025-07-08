import re
from .utils import *
from .main_class import *

import tree_sitter_c as tspython
from tree_sitter import Language, Parser, Node

C_LANGUAGE = Language(tspython.language())
parser = Parser(C_LANGUAGE)




def record_type(source_code: bytes) -> dict[str, str]:
    """
    解析 C 源代码，提取 typedef、struct、union 和 enum 的完整定义并返回一个字典。

    Args:
        source_code (bytes): C 源代码的字节串。
        parser (Parser): 已经设置好 C 语言的 tree-sitter 解析器。

    Returns:
        dict: 一个字典，键是类型名称，值是类型定义的完整源代码字符串。
    """
    tree = parser.parse(source_code)
    recorded = []
    type_dict = {}

    def get_node_source(node: Node) -> str:
        return source_code[node.start_byte:node.end_byte].decode('utf-8')

    def traverse(node: Node):
        if node.type == "type_definition":
            typedef_name_node = None
            for child in node.children:
                if child.type == "type_identifier":
                    typedef_name_node = child
                    break
            if typedef_name_node:
                name = typedef_name_node.text.decode('utf-8')
                if name not in recorded:
                    type_dict[name] = get_node_source(node)
                    recorded.append(name)
            return

        elif node.type == "struct_specifier":
            struct_name_node = None
            for child in node.children:
                if child.type == "type_identifier":
                    struct_name_node = child
                    break
            if struct_name_node:
                name = struct_name_node.text.decode('utf-8')
                if name not in recorded:
                    type_dict[name] = get_node_source(node) + ";"
                    recorded.append(name)
            return

        elif node.type == "union_specifier":
            union_name_node = None
            for child in node.children:
                if child.type == "type_identifier":
                    union_name_node = child
                    break
            if union_name_node:
                name = union_name_node.text.decode('utf-8')
                if name not in recorded:
                    type_dict[name] = get_node_source(node) + ";"
                    recorded.append(name)
            return

        elif node.type == "enum_specifier":
            enum_name_node = None
            for child in node.children:
                if child.type == "type_identifier":
                    enum_name_node = child
                    break
            if enum_name_node:
                name = enum_name_node.text.decode('utf-8')
                if name not in recorded:
                    type_dict[name] = get_node_source(node) + ";"
                    recorded.append(name)
            return

        for child in node.children:
            traverse(child)

    traverse(tree.root_node)
    return type_dict


def free_all_tu(tu_dict):
    keys = list(tu_dict.keys())
    for key in keys:
        del tu_dict[key]
    # 也可以调用 gc.collect() 强制回收
    import gc
    gc.collect()





def function_info_init(tu_dict, root_dir, function_name, file_cache, global_type_info_dict):
    """
    初始化函数信息，生成目标函数的FunctionInfo对象
    
    Args:
        tu_dict: 翻译单元字典
        root_dir: 根目录
        function_name: 函数名
        file_cache: 文件内容缓存
        global_type_info_dict: 全局类型信息字典
        
    Returns:
        生成的FunctionInfo对象
    """
    file_path = find_c_file_path(root_dir, function_name, tu_dict)
    if not file_path:
        print(f"错误：未找到函数 '{function_name}' 的定义文件")
        return None
        
    tu = create_tu(file_path, tu_dict)

    with open(file_path, 'rb') as f:
        content = f.read()
    type_dict = record_type(content)

    
    # 生成该tu的type_dict,并更新global_type_info_dict
    global_type_info_dict.update(type_dict)

    
    
    # 查找函数游标
    function_cursor = find_function_cursor(tu, function_name)
    if not function_cursor:
        print(f"错误：未找到函数 '{function_name}' 的定义")
        return None
    
    # 获取函数代码
    code = read_file_content(file_path, file_cache)
    content_range = record_content_range(function_cursor)
    function_code = record_range_content(code, content_range)
    
    # 获取函数返回类型
    func_type = function_cursor.result_type.spelling
    
    # 创建FunctionInfo对象
    function_info = FunctionInfo(
        file_path=file_path,
        name=function_name,
        code=function_code,
        callee_set=set(),
        func_type=func_type
    )
    
    # 处理函数参数，递归处理相关类型
    for param in function_cursor.get_arguments():
        
        # print(param)
        process_parameter(param, function_info.parameter_list,function_code)


    
    
    # 分析函数体中调用的函数
    find_function_calls(function_cursor, function_info)

    
    
    return function_info



def print_type_info_dict(type_info_dict, indent=0, printed_types=None):
    """
    打印类型信息字典的内容
    
    Args:
        type_info_dict: 类型信息字典
        indent: 缩进级别
        printed_types: 已打印过的类型集合，用于避免循环引用
    """
    if printed_types is None:
        printed_types = set()
    
    for type_name, type_info in type_info_dict.items():
        if type_name in printed_types:
            print(' ' * indent + f"类型: {type_name} (已打印过)")
            continue
        
        printed_types.add(type_name)
        print(' ' * indent + f"类型: {type_name}")
        print(' ' * (indent + 2) + f"代码: {type_info}")
        print()  # 添加空行分隔类型

def print_parameter(param, indent_level=0):
    """
    递归打印参数信息，包括结构体成员
    
    Args:
        param: 参数对象
        indent_level: 缩进级别
    """
    indent = "  " * indent_level
    
    # 确定参数类型的显示方式
    if isinstance(param.type, StructInfo):
        type_display = f"{param.type.type} (结构体)"
    else:
        type_display = str(param.type)
    
    # 显示数组和指针信息
    array_info = f"[{param.array_length}]" if param.array_length >= 0 else ""
    ptr_info = "*" if param.is_ptr else ""
    
    print(f"{indent}参数: {param.name}")
    print(f"{indent}  类型: {type_display}{ptr_info}{array_info}")
    
    # 如果是结构体类型，递归打印其成员
    if isinstance(param.type, StructInfo):
        print(f"{indent}  结构体成员:")
        for member in param.type.parameter_list:
            print_parameter(member, indent_level + 2)

def print_function_info(function_info, indent_level=0):
    """
    打印函数信息，包括递归打印参数列表
    
    Args:
        function_info: 函数信息对象
        indent_level: 缩进级别
    """
    indent = "  " * indent_level
    
    print(f"{indent}函数名: {function_info.name}")
    print(f"{indent}文件路径: {function_info.file_path}")
    print(f"{indent}返回类型: {function_info.func_type}")
    
    if function_info.callee_set:
        print(f"{indent}调用的函数: {', '.join(function_info.callee_set)}")
    
    if function_info.parameter_list:
        print(f"{indent}参数列表:")
        for param in function_info.parameter_list:
            print_parameter(param, indent_level + 1)
    
    if hasattr(function_info, 'annotation') and function_info.annotation:
        print(f"{indent}注释: {function_info.annotation}")
    
    print(f"{indent}代码:")
    code_lines = function_info.code.split('\n')
    for line in code_lines:
        print(f"{indent}  {line}")









