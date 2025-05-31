from dataclasses import dataclass

@dataclass
class CodeAnalyzerConfig:
    """配置参数类"""
    root_dir: str = None  # 原始输入
    input_dir: str = '2_input' # 统一格式的输入，可以手动注入 acsl 格式的前条件以及验证目标
    annotated_c_dir: str = '1_output' # vst 格式注释过前条件的，可以手动注入 vst 格式的前条件以及验证目标
    annotated_loop_dir:str = '2_output' # vst 格式完整注释
    generated_loop_dir :str = '3_output' # acsl 格式注释过前条件 验证目标 不变量
    output_dir:str = 'output' # acsl 格式完整注释

    

    function_name: str = None

    input_path:str =None
    annotated_c_file_path: str = None
    annotated_loop_c_file_path: str = None
    generated_loop_c_file_path: str = None
    output_path:str = None

    #  TT 以 root_dir 为唯一输入, 其他均自动生成
    pre_process:bool = True 
   
    # FT 以 input_dir 为唯一输入 
    # FF 以 input_dir 和 annotated_c_dir 为输入
    auto_annotation:bool = True 
   