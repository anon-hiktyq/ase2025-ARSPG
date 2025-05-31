import os
import subprocess
import re

import shutil

import tree_sitter_c as tspython
from tree_sitter import Language, Parser

C_LANGUAGE = Language(tspython.language())
parser = Parser(C_LANGUAGE)

# def setup_tree_sitter():
#     """设置tree-sitter解析器"""
#     # 确保tree-sitter-c库已经构建
#     if not os.path.exists('build/my-languages.so'):
#         # 克隆C语言grammar
#         if not os.path.exists('tree-sitter-c'):
#             subprocess.run(['git', 'clone', 'https://github.com/tree-sitter/tree-sitter-c.git'], check=True)
#
#         # 构建语言库
#         Language.build_library(
#             'build/my-languages.so',
#             ['tree-sitter-c']
#         )
#
#     C_LANGUAGE = Language('build/my-languages.so', 'c')
#     parser = Parser()
#     parser.set_language(C_LANGUAGE)
    
    # return parser

def collect_standard_headers(root_dir, parser):
    """收集项目中使用的所有标准库头文件"""
    standard_headers = set()
    
    # 标准库头文件列表
    std_headers = [
        "stdio.h", "stdlib.h", "string.h", "math.h", "time.h", "ctype.h",
        "assert.h", "limits.h", "float.h", "locale.h", "setjmp.h", "signal.h",
        "stdarg.h", "stddef.h", "errno.h", "time.h", "iso646.h", "wchar.h",
        "wctype.h", "complex.h", "fenv.h", "inttypes.h", "stdbool.h", "stdint.h",
        "tgmath.h", "stdalign.h", "stdatomic.h", "stdnoreturn.h", "threads.h", "uchar.h"
    ]
    
    def traverse_node(node):
        # 检查当前节点是否为系统库头文件
        if node.type == "system_lib_string":
            include_path = node.text.decode('utf-8')
            header_name = include_path[1:-1]  # 去除 < >
            if header_name in std_headers:
                # 找到父节点的preproc_include
                parent = node.parent
                if parent and parent.type == "preproc_include":
                    standard_headers.add(f"#include {include_path}")
        
        # 递归遍历所有子节点
        for child in node.children:
            traverse_node(child)
    
    # 遍历所有.c和.h文件
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith(('.c', '.h')):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8') as f:
                        content = f.read()
                except UnicodeDecodeError:
                    try:
                        with open(file_path, 'r', encoding='latin-1') as f:
                            content = f.read()
                    except:
                        print(f"无法读取文件: {file_path}")
                        continue
                
                # 使用tree-sitter解析文件
                tree = parser.parse(bytes(content, 'utf-8'))
                root_node = tree.root_node
                
                # 从根节点开始遍历整棵树
                traverse_node(root_node)
    
    return standard_headers

def preprocess_all_headers(root_dir, standard_headers, temp_dir):
    """预处理根目录中所有的头文件，删除标准库头文件引用"""
    processed_files = []
    
    # 遍历所有.h文件
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith('.h'):
                file_path = os.path.join(root, file)
                rel_path = os.path.relpath(file_path, root_dir)
                temp_file_path = os.path.join(temp_dir, rel_path)
                
                # 创建临时文件目录
                os.makedirs(os.path.dirname(temp_file_path), exist_ok=True)
                
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                except Exception as e:
                    print(f"无法读取文件 {file_path}: {e}")
                    continue
                
                # 删除标准库头文件引用
                for header in standard_headers:
                    content = re.sub(rf'#include\s*<{header}>', '', content)
                
                # 写入临时文件
                with open(temp_file_path, 'w', encoding='utf-8') as f:
                    f.write(content)
                
                processed_files.append((file_path, temp_file_path))
    
    return processed_files

def preprocess_file(file_path, output_dir, include_dirs=None, standard_headers=None, temp_headers_dir=None):
    """使用clang预处理文件，移除宏"""
    if include_dirs is None:
        include_dirs = []
    if standard_headers is None:
        standard_headers = set()
    
    # 创建输出目录
    os.makedirs(output_dir, exist_ok=True)
    
    # 构建输出文件路径
    base_name = os.path.basename(file_path)
    output_i_file = os.path.join(output_dir, f"{os.path.splitext(base_name)[0]}.i")
    
    # 创建临时文件，删除标准库头文件引用
    temp_file = os.path.join(output_dir, f"temp_{base_name}")
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # 删除标准库头文件引用
    for header in standard_headers:
        content = re.sub(rf'#include\s*<{header}>', '', content)
    
    with open(temp_file, 'w', encoding='utf-8') as f:
        f.write(content)
    
    # 构建clang命令
    cmd = ['clang', '-E', temp_file, '-o', output_i_file]
    
    # 添加包含目录
    if temp_headers_dir:
        cmd.extend(['-I', temp_headers_dir])
    for include_dir in include_dirs:
        cmd.extend(['-I', include_dir])
    
    # 执行预处理
    try:
        subprocess.run(cmd, check=True)
        # 删除临时文件
        os.remove(temp_file)
        return output_i_file
    except subprocess.CalledProcessError as e:
        print(f"预处理文件失败: {e}")
        # 删除临时文件
        if os.path.exists(temp_file):
            os.remove(temp_file)
        return None

def convert_to_c_file(i_file_path, standard_headers, output_dir):
    """将.i文件转换为.c文件，并添加标准库头文件"""
    # 创建输出目录
    os.makedirs(output_dir, exist_ok=True)
    
    # 构建输出文件路径
    base_name = os.path.basename(i_file_path)
    output_c_file = os.path.join(output_dir, f"{os.path.splitext(base_name)[0]}.c")
    
    try:
        with open(i_file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except UnicodeDecodeError:
        with open(i_file_path, 'r', encoding='latin-1') as f:
            content = f.read()
    
    # 移除预处理器生成的行标记
    content = re.sub(r'# \d+ ".*".*\n', '', content)
    
    # 添加标准库头文件
    headers_str = '\n'.join(standard_headers)
    if headers_str:
        content = headers_str + '\n\n' + content
    
    # 写入.c文件
    with open(output_c_file, 'w', encoding='utf-8') as f:
        f.write(content)
    
    return output_c_file

# def process_all_c_files(root_dir):
#     """处理根目录中的所有.c文件"""
#     processed_files = []
    
#     # 遍历所有.c文件
#     for root, _, files in os.walk(root_dir):
#         for file in files:
#             if file.endswith('.c'):
#                 file_path = os.path.join(root, file)
#                 print(f"\n正在处理文件: {file_path}")
                
#                 # 对每个.c文件执行宏移除操作
#                 output_file = remove_macros(root_dir, file_path)
#                 if output_file:
#                     processed_files.append((file_path, output_file))
#                     print(f"成功处理文件: {file_path} -> {output_file}")
#                 else:
#                     print(f"处理文件失败: {file_path}")
    
#     return processed_files

# def remove_macros(root_dir, target_file):
#     """主函数：移除非标准库宏并生成预处理后的文件"""
#     # 设置输出目录在root_dir下
#     output_dir = os.path.join(root_dir, "1_nonmacro_file")
#     os.makedirs(output_dir, exist_ok=True)
    
#     # 获取目标文件的相对路径（用于保持输出文件的目录结构）
#     try:
#         rel_path = os.path.relpath(target_file, root_dir)
#         output_subdir = os.path.join(output_dir, os.path.dirname(rel_path))
#         os.makedirs(output_subdir, exist_ok=True)
#     except ValueError:
#         # 如果目标文件不在根目录下，则直接放在输出目录中
#         output_subdir = output_dir
    
#     # 收集标准库头文件
#     print("正在收集标准库头文件...")
#     standard_headers = collect_standard_headers(root_dir, parser)
#     print(f"找到 {len(standard_headers)} 个标准库头文件引用")
    
#     # 提取标准库头文件名称
#     std_header_names = set()
#     for header in standard_headers:
#         match = re.search(r'<([^>]+)>', header)
#         if match:
#             std_header_names.add(match.group(1))
    
#     # 创建临时目录用于处理头文件
#     temp_dir = os.path.join(os.getcwd(), "temp_preprocessed")
#     temp_headers_dir = os.path.join(temp_dir, "headers")
#     os.makedirs(temp_headers_dir, exist_ok=True)
    
#     # 预处理所有头文件
#     print("正在预处理所有头文件...")
#     processed_headers = preprocess_all_headers(root_dir, std_header_names, temp_headers_dir)
#     print(f"预处理了 {len(processed_headers)} 个头文件")
    
#     # 获取目标文件的绝对路径
#     target_file_abs = os.path.abspath(target_file)
    
#     # 获取包含目录（目标文件所在目录及根目录）
#     include_dirs = [os.path.dirname(target_file_abs), root_dir]
    
#     # 预处理目标文件
#     print(f"正在预处理文件: {target_file}")
#     i_file = preprocess_file(target_file_abs, temp_dir, include_dirs, std_header_names, temp_headers_dir)
    
#     if i_file:
#         # 转换为.c文件
#         print("正在转换为.c文件...")
#         # 使用相对路径构建输出文件路径，保持目录结构
#         base_name = os.path.basename(i_file)
#         final_output_file = os.path.join(output_subdir, f"{os.path.splitext(base_name)[0]}.c")
        
#         # 读取预处理后的内容
#         try:
#             with open(i_file, 'r', encoding='utf-8') as f:
#                 content = f.read()
#         except UnicodeDecodeError:
#             with open(i_file, 'r', encoding='latin-1') as f:
#                 content = f.read()
        
#         # 移除预处理器生成的行标记
#         content = re.sub(r'# \d+ ".*".*\n', '', content)
        
#         # 添加标准库头文件
#         headers_str = '\n'.join(standard_headers)
#         if headers_str:
#             content = headers_str + '\n\n' + content
        
#         # 写入.c文件
#         os.makedirs(os.path.dirname(final_output_file), exist_ok=True)
#         with open(final_output_file, 'w', encoding='utf-8') as f:
#             f.write(content)
        
#         print(f"生成的文件: {final_output_file}")
        
#         # 清理临时目录
#         shutil.rmtree(temp_dir, ignore_errors=True)
        
#         return final_output_file
#     else:
#         print("预处理失败")
#         # 清理临时目录
#         shutil.rmtree(temp_dir, ignore_errors=True)
#         return None

def process_all_c_files(root_dir, output_dir=None):
    """处理根目录中的所有.c文件并输出到指定目录
    
    Args:
        root_dir: 输入文件根目录
        output_dir: 指定输出目录（默认为root_dir/non_macro_output）
    """
    processed_files = []
    
    # 设置输出目录
    if output_dir is None:
        output_dir = os.path.join(root_dir, "non_macro_output")
    
    # 遍历所有.c文件
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                print(f"\n正在处理文件: {file_path}")
                
                # 对每个.c文件执行宏移除操作
                output_file = remove_macros(root_dir, file_path, output_dir)
                if output_file:
                    processed_files.append((file_path, output_file))
                    print(f"成功处理文件: {file_path} -> {output_file}")
                else:
                    print(f"处理文件失败: {file_path}")
    
    return processed_files

def remove_macros(root_dir, target_file, output_dir=None):
    """移除非标准库宏并生成预处理后的文件到指定目录
    
    Args:
        root_dir: 输入文件根目录
        target_file: 要处理的.c文件
        output_dir: 指定的输出目录
    """
    # 确保输出目录存在
    os.makedirs(output_dir, exist_ok=True)
    
    # 获取目标文件的相对路径（用于保持输出文件的目录结构）
    try:
        rel_path = os.path.relpath(target_file, root_dir)
        output_subdir = os.path.join(output_dir, os.path.dirname(rel_path))
        os.makedirs(output_subdir, exist_ok=True)
    except ValueError:
        # 如果目标文件不在根目录下，则直接放在输出目录中
        output_subdir = output_dir
    
    # 收集标准库头文件
    print("正在收集标准库头文件...")
    standard_headers = collect_standard_headers(root_dir, parser)
    print(f"找到 {len(standard_headers)} 个标准库头文件引用")
    
    # 提取标准库头文件名称
    std_header_names = set()
    for header in standard_headers:
        match = re.search(r'<([^>]+)>', header)
        if match:
            std_header_names.add(match.group(1))
    
    # 创建临时目录用于处理头文件
    temp_dir = os.path.join(os.getcwd(), "temp_preprocessed")
    temp_headers_dir = os.path.join(temp_dir, "headers")
    os.makedirs(temp_headers_dir, exist_ok=True)
    
    # 预处理所有头文件 
    print("正在预处理所有头文件...")
    processed_headers = preprocess_all_headers(root_dir, std_header_names, temp_headers_dir)
    print(f"预处理了 {len(processed_headers)} 个头文件")
    
    # 获取目标文件的绝对路径
    target_file_abs = os.path.abspath(target_file)
    
    # 获取包含目录（目标文件所在目录及根目录）
    include_dirs = [os.path.dirname(target_file_abs), root_dir]
    
    # 预处理目标文件
    print(f"正在预处理文件: {target_file}")
    i_file = preprocess_file(target_file_abs, temp_dir, include_dirs, std_header_names, temp_headers_dir)
    
    if i_file:
        # 转换为.c文件
        print("正在转换为.c文件...")
        # 使用相对路径构建输出文件路径，保持目录结构
        base_name = os.path.basename(i_file)
        final_output_file = os.path.join(output_subdir, f"{os.path.splitext(base_name)[0]}.c")
        
        # 读取预处理后的内容
        try:
            with open(i_file, 'r', encoding='utf-8') as f:
                content = f.read()
        except UnicodeDecodeError:
            with open(i_file, 'r', encoding='latin-1') as f:
                content = f.read()
        
        # 移除预处理器生成的行标记
        content = re.sub(r'# \d+ ".*".*\n', '', content)
        
        # 添加标准库头文件
        headers_str = '\n'.join(standard_headers)
        if headers_str:
            content = headers_str + '\n\n' + content
        
        # 写入.c文件
        os.makedirs(os.path.dirname(final_output_file), exist_ok=True)
        with open(final_output_file, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"生成的文件: {final_output_file}")
        
        # 清理临时目录
        shutil.rmtree(temp_dir, ignore_errors=True)
        
        return final_output_file
    else:
        print("预处理失败")
        # 清理临时目录
        shutil.rmtree(temp_dir, ignore_errors=True)
        return None

if __name__ == "__main__":
    import sys
    
    if len(sys.argv) == 1:
        # 默认测试路径
        root_dir = './1_input/test2'
        process_all_c_files(root_dir)
    elif len(sys.argv) == 2:
        # 只提供根目录，处理所有.c文件
        root_dir = sys.argv[1]
        process_all_c_files(root_dir)
    elif len(sys.argv) == 3:
        # 提供根目录和特定的.c文件
        root_dir = sys.argv[1]
        target_file = sys.argv[2]
        remove_macros(root_dir, target_file)
    else:
        print("用法: python remove_macro.py [根目录] [目标C文件(可选)]")
        sys.exit(1)
