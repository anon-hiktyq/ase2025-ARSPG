import subprocess
import os


def create_post_dict_list(data:str)->list:
    # 将输入字符串按两段分割
    data_list = data.strip().split("\n\n")
    output = []
    for index, item_str in enumerate(data_list, start=1):  # 从1开始递增
        # 分割每个条目为 return_value 和 path_condition
        lines = item_str.split("\n")
        return_value = lines[0].split(": ")[1]
        path_condition = lines[1].split(": ")[1]

        # 为每个条目分配递增的 ID
        item = {
            "id": index,  # 使用递增的数字作为 id
            "return_value": return_value,
            "path_condition": path_condition
        }
        output.append(item)
    return output


def delete_file_if_exists(file_path):
    """如果文件存在，则删除文件"""
    # 构建完整的文件路径
    file_path = os.path.join('../sac_c_parser/test', file_path)

    if os.path.exists(file_path):  # 检查文件是否存在
      #  print(f"File found: {file_path}. Deleting the file.")
        os.remove(file_path)  # 删除文件
    #else:
      #  print(f"File not found: {file_path}. No file to delete.")


def create_post(file_name: str,annotated_loop_file_path: str)-> list:

    output = None
    # 定义文件路径
    goal_file = f"../../SpecAutoAnnotator/0_goal/{file_name}_goal.v"
    proof_auto_file = f"../../SpecAutoAnnotator/0_goal/{file_name}_proof_auto.v"
    proof_manual_file = f"../../SpecAutoAnnotator/0_goal/{file_name}_proof_manual.v"
    input_file = f"../../SpecAutoGen/{annotated_loop_file_path}/{file_name}.c"

    # 检查文件是否存在，存在则删除
    for file_path in [goal_file, proof_auto_file, proof_manual_file]:
        delete_file_if_exists(file_path)

    # 定义命令和参数
    command = [
        "build/symexec",
        f"--goal-file={goal_file}",
        f"--proof-auto-file={proof_auto_file}",
        f"--proof-manual-file={proof_manual_file}",
        '--no-logic-path --strategy-file=../examples/common_DSLFileLists',
        f"--input-file={input_file}"
    ]
    # print(' '.join(command))

    # 运行命令，捕获输出
    try:
        result = subprocess.run(command, cwd='../sac_c_parser/test',
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        
        
        output = result.stdout.split('+++++')

        output = [
            block for block in output 
            if 'return_value' in block and 'path_condition' in block
        ]


        error = result.stderr

        if 'error' in error:
            return 'SymExec Failed'
        elif len(output):
            output = output[-1].strip()
        else:
            return 'SymExec Failed'
            # 处理没有找到分隔符的情况
            # raise ValueError("\n\n+++++\n\033[7m\033[31mThe expected delimiter '+++++' was not found in the output.即VST没有成功生成postcondition\033[0m\n+++++\n\n")
            
        output = create_post_dict_list(output)
    except Exception as e:
        print(f"An error occurred: {e}")

    return output

def combine_post(data) -> str:
    # 提取所有 path_condition 并用 || 连接
    print('-'* 40)
    print('路径约束与返回值')
    for item in data:
        if not item['return_value'] == "NULL":
           # return_value = str(item['return_value'])
            print("path:"+ item['path_condition'])
           # item['path_condition'] = item['path_condition'] + f" && __return == {return_value}"
    path_conditions = [f"({item['path_condition']})" for item in data]
    combined_post_condition = ' || '.join(path_conditions)

    # 输出结果


    print("Combined path condition:")
    print(combined_post_condition)
    print('-'* 40+'\n')
    return combined_post_condition

def update_annotation(annotation:str, combined_post_condition:list)->str:
    ensure_part = combine_post(combined_post_condition)
    part = annotation.split('Ensure')[0].strip()
    return f'{part}\nEnsure {ensure_part}\n*/'



if __name__ == "__main__":
    file_name = './4_json_file/max3.json'
    combine_post(file_name)
