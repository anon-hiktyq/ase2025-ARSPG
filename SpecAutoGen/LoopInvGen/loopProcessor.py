import argparse
import subprocess
import os
import re
import json
from SpecAutoAnnotator.main_class import *
from Config import CodeAnalyzerConfig

class LoopProcessor:
    def __init__ (self, info : FunctionInfo, config: CodeAnalyzerConfig):
        """
        初始化 LoopProcessor 对象。
        :param file_name: 文件名（不带扩展名）
        """
        
        self.function_info = info
        self.file_name = info.name
        self.code = info.code
        self.loop_contents = None  # 存储循环内容
        self.sorted_indices = None  # 存储排序后的索引
        self.loop_entries = []  # 存储提取的循环条目

        self.goal_file = f"../ip_postcond/goal/{self.file_name}_goal.v"
        self.proof_auto_file = f"../ip_postcond/goal/{self.file_name}_proof_auto.v"
        self.proof_manual_file = f"../ip_postcond/goal/{self.file_name}_proof_manual.v"
        # self.input_file = f"symexe/input/{self.file_name}.c"
        # self.output_file =f"symexe/output/{self.file_name}.c"
        # self.iter_file = f"../../LoopInvGen_V7/symexe/output/{self.file_name}.c"
        self.input_file = f"../SpecAutoGen/{config.annotated_c_file_path}/{self.file_name}.c"
        self.output_file =f"../SpecAutoGen/{config.annotated_loop_c_file_path}/{self.file_name}.c"
        self.iter_file = f"../../SpecAutoGen/{config.annotated_loop_c_file_path}/{self.file_name}.c"
        self.json_file = f'loop/{self.file_name}.json'

    def delete_file_if_exists(self, file_path):
        """
        如果文件存在，则删除文件。
        :param file_path: 文件路径
        """
        file_path = os.path.join('../sac_c_parser/test', file_path)
        if os.path.exists(file_path):
           # print(f"File found: {file_path}. Deleting the file.")
            os.remove(file_path)
        #else:
          #  print(f"File not found: {file_path}. No file to delete.")
    
   

    # 寻找每个 循环 开头和结尾的地方
    def process_loop(self,code):
    

        def determine_inner_loops(loop_info):
            """
            判断每个循环是否是内层循环。
            参数:
                loop_info: list of tuples, 每个元素为 (start_pos, end_pos, loop_index)
            返回:
                list of bool，表示每个循环是否是内层循环（按 loop_info 输入顺序）
            """
            inner_flags = [False] * len(loop_info)
            
            
            # 遍历所有循环对 (i, j)
            for j in range(len(loop_info)):
                s_j, e_j, idx_j = loop_info[j]
                for i in range(len(loop_info)):
                    if i == j:
                        continue
                    s_i, e_i, idx_i = loop_info[i]
                    # 如果循环i完全包含循环j：i的起始更早，结束更晚
                    if s_i < s_j and e_i > e_j:
                        inner_flags[j] = True
                        break  # 只要被一个外层循环包含，即可判定为内层
            
            return inner_flags
        # 将代码拆分成单字符的列表
        code_list = list(code)
        
        # 查找所有的 for 或 while 循环位置
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
        loop_contents = []
        loop_indices=[]
        
        # 处理每一个循环
        for idx, match in enumerate(matches):
            # 循环的起始位置
            loop_start = match.start()    

            at_index = loop_start

            loop_head= code_list[at_index] 
            
            code_list[at_index-1] = f'\n {code_list[at_index -1 ]}/*@ Print user assertion at number LoopEntry_{idx}*/ \n'
            code_list[at_index] = f'/*@ Inv emp */ /*{idx}*/ \n {code_list[at_index]}'

            
            # 在循环后找到第一个 { 对应的 }
            brace_count = 0
            loop_end = match.end()
            end_index = loop_end
            while brace_count >= 0:
                if code_list[end_index] == '{':
                    brace_count += 1
                elif code_list[end_index] == '}':
                    brace_count -= 1
                end_index += 1

            # 将 (at_index,end_index, idx) 压入列表
            loop_indices.append((at_index,end_index, idx))
          

            # 提取循环内容
            loop_content = loop_head + ''.join(code_list[loop_start +1:end_index])

           
            # 修改注释为 acsl 格式
            assert_pattern = r'/\*@\s*(.*?)\s*\*/'
    
            # 替换为 /*@ assert xxxxxx ;*/
            loop_content = re.sub(assert_pattern, r'/*@ assert \1; */', loop_content)

            loop_content = loop_content.replace('=>','==>')
            
            
            # 打印循环内容
            # print(f"LoopContent_{idx}:\n{loop_content}\n")
            loop_contents.append(loop_content)
        
        # print(loop_indices)

        inner_flags = determine_inner_loops(loop_indices)

        
        # 按 end_index 从小到大排序
        sorted_indices = [x[2] for x in sorted(loop_indices, key=lambda x: x[1])]
        
            
        # 将字符列表重新拼接成字符串
        return ''.join(code_list),loop_contents,sorted_indices,inner_flags
    


    def get_loop_content(self,code,ridx):

        # 查找所有的 for 或 while 循环位置
        code_list = list(code)
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        loop_content = None
        matches = list(re.finditer(loop_pattern, code))
        
        # 处理每一个循环
        for idx, match in enumerate(matches):
            if idx == ridx:
                # 循环的起始位置
                loop_start = match.start()    

                at_index = loop_start

                loop_head = code_list[at_index] 
            
                # 在循环后找到第一个 { 对应的 }
                brace_count = 0
                loop_end = match.end()
                end_index = loop_end
                while brace_count >= 0:
                    if code_list[end_index] == '{':
                        brace_count += 1
                    elif code_list[end_index] == '}':
                        brace_count -= 1
                    end_index += 1

                # 提取循环内容
                loop_content = loop_head + ''.join(code_list[loop_start +1:end_index])
                break

        return loop_content

    
    def process_loop_file(self,input_file_path,output_file_path):
        # 读取原始文件内容
        if input_file_path != None:
            with open(input_file_path, 'r', encoding='utf-8') as infile:
                code = infile.read()
        else:
            code = self.code
        
        # 调用 process_code 处理代码
        processed_code = self.process_loop(code)[0]
        loop_contents = self.process_loop(code)[1]
        sorted_indices = self.process_loop(code)[2]
        inner_flags = self.process_loop(code)[3]


        # 将处理后的代码写入新文件
        with open(output_file_path, 'w', encoding='utf-8') as outfile:
            outfile.write(processed_code)

        return loop_contents,sorted_indices,inner_flags

    def get_loop_entries(self, text):
        """
        使用正则表达式从文本中提取 LoopEntry_X 的条件。
        :param text: 输入的文本
        :return: 提取的循环条目列表
        """
       
        pattern = r"LoopEntry_(\d+):\s*\n([^\n]*)"
        matches = re.findall(pattern, text)

        self.loop_entries = []
        for match in matches:
            loop_id = int(match[0])  # 提取编号
            condition = match[1].strip()  # 提取条件并去掉首尾空白
            self.loop_entries.append((loop_id, condition))

        # 按 loop_id 排序
        self.loop_entries.sort(key=lambda x: x[0])
        return self.loop_entries

    def write_loops_to_json(self):
        """
        将循环内容和条目写入 JSON 文件。
        """

        if len(self.loop_contents) != len(self.loop_entries):
            print(self.loop_contents)
            print(self.loop_entries)
            raise ValueError("loop_contents 和 loop_entries 的长度必须一致")

        data = []
        for entry, content in zip(self.loop_entries, self.loop_contents):
            loop_id, condition = entry
            data.append({
                "loop_id": loop_id,
                "condition": condition,
                "content": content
            })

        with open(self.json_file, 'w') as f:
            json.dump(data, f, indent=4)

        print(f"Successfully generated {self.json_file}")

    def run_symexec(self):
        """
        运行 symexec 命令并处理输出。
        """
        command = [
            "build/symexec",
            f"--goal-file={self.goal_file}",
            f"--proof-auto-file={self.proof_auto_file}",
            f"--proof-manual-file={self.proof_manual_file}",
            f"--input-file={self.iter_file}"
        ]

        try:
            result = subprocess.run(
                command,
                cwd='../sac_c_parser/test',
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            if result.stderr:
                print(result.stderr.strip())
                self.get_loop_entries(result.stderr)
                self.write_loops_to_json()

        except Exception as e:
            print(f"An error occurred: {e}")

    def init_execute(self):
        # 处理输入文件
        self.loop_contents, self.sorted_indices,self.inner_flags = self.process_loop_file(self.input_file,self.output_file)

        for idx in self.sorted_indices:
            print(f"Loop {idx} : {'Inner' if self.inner_flags[idx] else 'Outer'}")
        print("Sorted indices:", self.sorted_indices)


    def execute(self):

        # 检查并删除旧文件
        for file_path in [self.goal_file, self.proof_auto_file, self.proof_manual_file]:
            self.delete_file_if_exists(file_path)

        # 运行 symexec 命令
        self.run_symexec()

    
    def update_loop_content(self,code,new_loop_content,ridx):
        # 将代码拆分成单字符的列表

        code_list = list(code)
        
        # 查找所有的 for 或 while 循环位置
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
       
        # 处理每一个循环
        for idx, match in enumerate(matches):
           
            # 循环的起始位置
            if idx == ridx:

                loop_start = match.start()  
                 
                at_index = -1  # 默认值，如果没有找到 '@' 就返回 -1
                for i in range(loop_start - 1, -1, -1):  # 从 loop_start - 1 开始，反向遍历
                    if code_list[i] == '@':
                        at_index = i
                        break  # 找到第一个 '@'，跳出循环

                at_index = at_index -2

                # 在循环后找到第一个 { 对应的 }
                brace_count = 0
                loop_end = match.end()
                end_index = loop_end
                while brace_count >= 0:
                    if code_list[end_index] == '{':
                        brace_count += 1
                    elif code_list[end_index] == '}':
                        brace_count -= 1
                    end_index += 1
                


        # 替换循环内容
        updated_code = (
            ''.join(code_list[:at_index]) +  # 循环之前的部分
            new_loop_content +                   # 替换后的循环内容
            ''.join(code_list[end_index:])   # 循环之后的部分
        )
            
        # 将字符列表重新拼接成字符串
        return updated_code

    


# def main():
#   # 创建解析器
#     parser = argparse.ArgumentParser(description="Read file_name from command-line arguments.")
#     parser.add_argument('file_name', type=str, help="The name of the file without extension")

#   # 解析参数
#     args = parser.parse_args()

#   # 创建 LoopProcessor 对象并执行
#     processor = LoopProcessor(args.file_name)
#     processor.init_execute()
#     processor.execute()


# if __name__ == "__main__":
#     main()