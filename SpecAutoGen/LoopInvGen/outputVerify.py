import argparse
import subprocess
from .syntaxChecker import SyntaxChecker
from Config import CodeAnalyzerConfig
import re

class OutputVerifier:
    def __init__(self,config:CodeAnalyzerConfig):
        self.config = config
        self.syntax_error = ''
        self.valid_error_list = []
        self.verify_error_list = []
        self.verify_result = []
        self.validate_result =[]

    def print_errors(self, error_list):
        for error in error_list:
            print(error[0])  # 打印错误描述
            print(error[1])  # 打印错误文件位置
            print(error[2])  # 打印错误行内容
            print()
    

    def extract_semantic_error(self,error_message):
        # 使用正则表达式提取文件名和行号
        pattern = r'file\s+([\w\/\.\-]+),\s+line\s+(\d+)'
        match = re.search(pattern, error_message)
        
        if match:
            file_path = match.group(1)
            line_number = int(match.group(2))  # 转换为整数

            try:
                with open(file_path, 'r') as file:
                    # 读取文件的所有行
                    lines = file.readlines()
                    # 检查行号是否在文件范围内
                    if 1 <= line_number <= len(lines):
                        error_line = lines[line_number - 1].strip()  # 提取错误行内容
                    else:
                        error_line = None  # 行号超出范围
                    
            except FileNotFoundError:
                print(f"Error: File '{file_path}' not found.")
                return None, None

            # 构造错误位置信息和错误行内容信息
            error_location_msg = f"Error found in file: {file_path} at line: {line_number}"
            error_content_msg = f"Error line content: {error_line}" if error_line else "Error line content: Line number out of range or file could not be read."

            return error_location_msg, error_content_msg
        
        else:
            return None, None
    

    def check_valid_pairs(self, filter_invs):
        results = []
        # 按相邻相同的元素分组
        for i in range(0, len(filter_invs), 2):
            if "Valid" in str(filter_invs[i]) and "Valid" in str(filter_invs[i+1]):
                results.append(True)
            else:
                results.append(False)
        return results

    def check_verify_target(self, filter_contents):
        results = []
        for content in filter_contents:
            if 'Valid' in content:
                results.append(True)
            else:
                results.append(False)
        return results

    def filter_goal_assertion(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Assertion (")]

    def filter_invariant(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Establishment of Invariant") or line.strip().startswith("Goal Preservation of Invariant")]

    def parse_args(self):
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def run(self,file_name=None):

        if file_name != None:
            file_path = f"{self.config.generated_loop_c_file_path}/{file_name}.c"
        else :
            args = self.parse_args()
            file_path = f"{self.config.generated_loop_c_file_path}/{args.file_name}.c"

        # syntax_msg = subprocess.run(['python3', 'syntaxChecker.py', file_path], capture_output=True, text=True).stdout
        # print(syntax_msg)

        checker = SyntaxChecker()
        checker.run(file_path)
        syntax_msg = checker.syntax_msg

        if syntax_msg !='syntax Correct':
            self.syntax_error = syntax_msg
        else:
            frama_c_command = "frama-c"
            wp_command = [frama_c_command, "-wp", "-wp-print", "-wp-timeout", "3", "-wp-prover", "z3", "-wp-model", "Typed+Caveat", file_path]
            result = subprocess.run(wp_command, capture_output=True, text=True, check=True)
            spliter = '------------------------------------------------------------'
            content = result.stdout
            contents = content.split(spliter)

            filter_invs = self.filter_invariant(contents)
            self.validate_result = self.check_valid_pairs(filter_invs)

            for item in filter_invs:
                if 'Valid' not in item:
                    valid_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(valid_error_msg)
                    self.valid_error_list.append((valid_error_msg.strip(), error_location_msg, error_content_msg))

            if config.debug:
                print('Validate:')
                print(self.validate_result)
                print()
            self.print_errors(self.valid_error_list)

            filter_contents = self.filter_goal_assertion(contents)
            self.verify_result = self.check_verify_target(filter_contents)

            for item in filter_contents:
                if 'Valid' not in item:
                    verify_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(verify_error_msg)
                    self.verify_error_list.append((verify_error_msg.strip(), error_location_msg, error_content_msg))
            if config.debug:
                print('Verify:')
                print(self.verify_result)
                print()
            self.print_errors(self.verify_error_list)

    

if __name__ == "__main__":
    verifier = OutputVerifier()
    verifier.run()