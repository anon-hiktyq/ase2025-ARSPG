from dataclasses import dataclass

@dataclass
class CodeAnalyzerConfig:
    """代码分析器全局配置类
    
    属性:
        root_dir (str): 项目根目录路径
        input_dir (str): 预处理输入目录（默认'2_input'）
        annotated_c_dir (str): 带VST格式注释的中间目录（默认'1_output'）
        annotated_loop_dir (str): 完整循环注释目录（默认'2_output'）
        generated_loop_dir (str): ACSL格式不变量生成目录（默认'3_output'）
        output_dir (str): 最终输出目录（默认'output'）
    """
    """配置参数类"""
    root_dir: str = None  # 原始输入
    input_dir: str = '2_input' # 统一格式的输入，可以手动注入 acsl 格式的前条件以及验证目标
    annotated_c_dir: str = '1_output' # vst 格式注释过前条件的，可以手动注入 vst 格式的前条件以及验证目标
    annotated_loop_dir:str = '2_output' # vst 格式完整注释
    generated_loop_dir :str = '3_output' # acsl 格式注释过前条件 验证目标 不变量
    output_dir:str = 'output' # acsl 格式完整注释
    log_dir:str = 'log'
    
    function_name: str = None

    input_path:str =None
    annotated_c_file_path: str = None
    annotated_loop_c_file_path: str = None
    generated_loop_c_file_path: str = None
    output_path:str = None

    #  TT 以 root_dir 为唯一输入, 其他均自动生成
    pre_process:bool = True 
    debug:bool = True
    generlization:bool = True
   
    # FT 以 input_dir 为唯一输入 
    # FF 以 input_dir 和 annotated_c_dir 为输入
    auto_annotation:bool = True

@dataclass
class LLMConfig:
    # API 模型的配置
    use_api_model = True # 控制是使用 API 模型还是本地 Transformers 模型
    api_model:str = "gpt-4o" # API 模型的名称，例如 "gpt-4o"
    api_key:str = "my-key" # 你的 OpenAI 或兼容 API 的密钥
    base_url:str = "https://yunwu.ai/v1" # API 的 base_url
    api_temperature = 0.7 # API 调用的温度参数
    api_top_p=0.9
    think_mode_enabled = False
    











   