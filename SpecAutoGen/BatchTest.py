from Config import CodeAnalyzerConfig
from MainProcessor import FunctionProcessor
import os

def list_files_os(folder_path):
    file_names = []
    for entry in os.listdir(folder_path):
        full_path = os.path.join(folder_path, entry)
        if os.path.isfile(full_path):
            file_names.append(entry)
    return file_names


# 使用示例
if __name__ == '__main__':

    name_list = list_files_os('./2_input/test_ip')
    log_dir = './log/'

    for name in name_list:
       
        # 配置参数
        name =name.split('.')[0]
        log_path = os.path.join(log_dir, f'{name}Fun.log')
        
        if os.path.exists(log_path):
            continue

        config = CodeAnalyzerConfig(
            root_dir='1_input/test_ip',
            function_name=f'{name}Fun',
            pre_process= False,
            auto_annotation= True,
            debug = False,
            generlization = True
        )
    
        # 执行分析
        processor = FunctionProcessor(config)
        processor.run_analysis()
        