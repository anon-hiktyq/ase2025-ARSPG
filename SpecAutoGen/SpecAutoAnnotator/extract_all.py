import clang.cindex
import re
from .utils import create_tu, read_file_content, get_type_name, is_from_standard_library, get_underlying_type
from .utils import record_content_range, record_range_content,find_function_cursor, find_c_file_path
from .main_class import *

import tree_sitter_c as tspython
from tree_sitter import Language, Parser,Node

C_LANGUAGE = Language(tspython.language())
parser = Parser(C_LANGUAGE)

clang.cindex.Config.set_library_path('/usr/lib/llvm-18/lib')


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


def extract_global_variable(node, tu_var_dict, tu_item_dict):
    """
    从全局变量节点中提取信息并更新到global_dict中

    :param node: 全局变量的cursor节点
    :param tu_var_dict: 全局变量信息字典
    :param tu_item_dict: 全局项目字典
    """
    # 忽略来自标准库的定义
    if is_from_standard_library(node):
        return

    file_path = node.location.file.name if node.location.file else None
    if not file_path:
        return

    # 生成唯一标识符
    identifier = node.spelling

    # 如果该全局变量已经处理过，直接返回
    if identifier in tu_var_dict:
        return

    # 检查父节点是否为翻译单元
    if node.semantic_parent.kind != clang.cindex.CursorKind.TRANSLATION_UNIT:
        return

    # 记录全局变量的类型
    tu_var_dict[identifier] = get_type_name(node.type.spelling)
    # print(f"Found global variable: {identifier} of type {tu_var_dict[identifier]} in {file_path}")

    # 记录项目到tu_item_dict，添加flag字段
    tu_item_dict[identifier] = {'kind': 'variable', 'flag': False}

# 新增类型解析工具函数
def resolve_underlying_type(cursor_type):
    """递归穿透指针/typedef/数组等类型修饰"""
    while True:
        # 处理指针类型
        if cursor_type.kind == clang.cindex.TypeKind.POINTER:
            cursor_type = cursor_type.get_pointee()
        # 处理typedef/elaborated类型
        elif cursor_type.kind == clang.cindex.TypeKind.ELABORATED:
            cursor_type = cursor_type.get_named_type()
        else:
            break
    return cursor_type

def process_parameter(cursor, parameter_list,function_code):
    """
    处理参数及其相关类型
    
    Args:
        cursor: 参数游标
        parameter_list: 参数列表，用于添加处理后的参数
    """
    param_name = cursor.spelling
    param_type_spelling = cursor.type.spelling


    

    ptr_depth = 0
    current_type_for_ptr = cursor.type
    while current_type_for_ptr.kind == clang.cindex.TypeKind.POINTER:
         current_type_for_ptr = current_type_for_ptr.get_pointee()
         ptr_depth += 1
    is_ptr = ptr_depth > 0

  
    # 获取基本类型名称
    base_type = get_type_name(param_type_spelling)
    
    # 检查是否是数组
    array_length = -1

    if '[' in param_type_spelling:
        array_match = re.search(r'\[(\d+)\]', param_type_spelling)
        if array_match:
            array_length = int(array_match.group(1))
    elif f'{param_name}[' in function_code:
        array_length = 'INT_MAX'

    
    # 检查是否是结构体类型
    is_struct = False
    param_type = base_type  # 默认使用基本类型名称

  
    
    if get_underlying_type(cursor.type).kind in [clang.cindex.TypeKind.RECORD, clang.cindex.TypeKind.ELABORATED]:
            is_struct = True
 

            type_decl = get_underlying_type(cursor.type).get_declaration()
            type_name = type_decl.spelling
            print(f'type_name:{type_name}')
            
            # 如果是结构体类型，创建StructInfo对象
            if type_name:
                # 创建结构体信息对象
                struct_info = StructInfo(type_name, [])
                
                # 递归查找结构体的所有字段
                find_struct_fields(type_decl, struct_info.parameter_list)
                
                # 使用结构体信息作为参数类型
                param_type = struct_info

    

    
    # 创建参数对象
    parameter = Parameter(
        name=param_name,
        type=param_type,  # 使用基本类型名称或StructInfo对象
        is_ptr=is_ptr,
        ptr_depth=ptr_depth,
        is_struct=is_struct,
        array_length=array_length
    )
    

    parameter_list.append(parameter)
    return parameter

def find_struct_fields(cursor, parameter_list):
    """
    递归查找结构体的所有字段
    
    Args:
        cursor: 结构体定义游标
        parameter_list: 参数列表，用于添加处理后的字段
    """
    # 直接处理当前节点的字段
    if cursor.kind == clang.cindex.CursorKind.FIELD_DECL:
        process_field(cursor, parameter_list)
        return
    
    # 递归处理所有子节点
    for child in cursor.get_children():
        # 如果是字段声明，处理它
        if child.kind == clang.cindex.CursorKind.FIELD_DECL:
            process_field(child, parameter_list)
        # 如果是其他类型的节点，递归查找
        else:
            find_struct_fields(child, parameter_list)

def process_field(cursor, parameter_list):
    """
    处理结构体字段
    
    Args:
        cursor: 字段游标
        parameter_list: 参数列表，用于添加处理后的参数
    """
    field_name = cursor.spelling
    field_type_spelling = cursor.type.spelling
    
    # 检查是否是指针
    ptr_depth = 0
    current_type_for_ptr = cursor.type
    while current_type_for_ptr.kind == clang.cindex.TypeKind.POINTER:
         current_type_for_ptr = current_type_for_ptr.get_pointee()
         ptr_depth += 1
    is_ptr = ptr_depth > 0
    
    # 获取基本类型名称
    base_type = get_type_name(field_type_spelling)
    
    # 检查是否是数组
    array_length = -1
    if '[' in field_type_spelling:
        array_match = re.search(r'\[(\d+)\]', field_type_spelling)
        if array_match:
            array_length = int(array_match.group(1))
    
    # 检查是否是结构体类型
    is_struct = False
    field_type = base_type  # 默认使用基本类型名称


    
    if get_underlying_type(cursor.type).kind in [clang.cindex.TypeKind.RECORD, clang.cindex.TypeKind.ELABORATED]:
        is_struct = True
        type_decl = get_underlying_type(cursor.type).get_declaration()
        type_name = type_decl.spelling
        print(f'type_name:{type_name}')
        
        # 如果是结构体类型，创建StructInfo对象
        if type_name:
            # 创建结构体信息对象
            struct_info = StructInfo(type_name, [])
            
            # 递归查找嵌套结构体的所有字段
            find_struct_fields(type_decl, struct_info.parameter_list)
            
            # 使用结构体信息作为字段类型
            field_type = struct_info
    
    # 创建参数对象
    parameter = Parameter(
        name=field_name,
        type=field_type,  # 使用基本类型名称或StructInfo对象
        is_ptr=is_ptr,
        ptr_depth= ptr_depth,
        is_struct=is_struct,
        array_length=array_length
    )
    
    parameter_list.append(parameter)



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

def find_function_calls(cursor, function_info):
    """
    递归查找函数调用
    
    Args:
        cursor: 当前游标
        function_info: 函数信息对象
    """
    if cursor.kind == clang.cindex.CursorKind.CALL_EXPR:
        callee_name = cursor.spelling
        if callee_name:
            function_info.callee_set.add(callee_name)
    
    for child in cursor.get_children():
        find_function_calls(child, function_info)

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

if __name__ == "__main__":

    # 缓存已读取的文件内容

    # file_path = '../Input/test7/main.c'
    # root_dir = '../Input/test7'

    # file_path = '../Input/SAMCode_V1.01/g4eapp.c'
    # root_dir = '../Input/SAMCode_V1.01'

    # file_path = '1_Input/test2/1_nonmacro_file/main.c'
    # root_dir = '1_Input/test2/1_nonmacro_file'
    # function_name = 'main'

    # file_path = '1_Input/test2/1_nonmacro_file/operations.c'
    # root_dir = '1_Input/test2/1_nonmacro_file'
    # function_name = 'calculateArea'

    file_path = '1_Input/test4/1_nonmacro_file/ThrusterCtrlLogic.c'
    root_dir = '1_Input/test4/1_nonmacro_file'
    function_name = 'ThrusterCtrlLogicFun'

    tu_dict = {}  # tu缓存
    file_cache = {}         #文件代码缓存
    tu = create_tu(file_path, tu_dict)
    global_type_info_dict = {}


    function_info = function_info_init(tu_dict, root_dir, function_name, file_cache, global_type_info_dict)

    print("\nTu type Tree:")
    print_type_info_dict(global_type_info_dict)
    print_function_info(function_info)







