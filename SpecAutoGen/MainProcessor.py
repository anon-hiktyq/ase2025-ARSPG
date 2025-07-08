import re
import sys
import logging 

from typing import List, Dict
from LoopInvGen.invGen import InvGenerator
# from target_program_init import function_init
from SpecAutoAnnotator.create_annotator import *
from SpecAutoAnnotator.create_post_condition import create_post, update_annotation
from SpecAutoAnnotator.extract_all import function_info_init,free_all_tu
from SpecAutoAnnotator.main_class import *
from SpecAutoAnnotator.remove_macro import process_all_c_files
from SpecAutoAnnotator.refine_postcond import refine_postcond
from SpecifactionVerify import SpecVerifier
from Config import CodeAnalyzerConfig
from Convertor import SpecificationConvertor
from DSL.Q2D import Post2DSL



# class DualOutput:
#     """双路输出类，同时输出到控制台和日志文件"""
#     def __init__(self, filename):
#         self.terminal = sys.stdout
#         try:
#             self.log = open(f'{filename}', 'a', encoding='utf-8')
#         except Exception as e:
#             print(f"Failed to open log file: {e}")
#             self.log = None

#     def write(self, message):
#         self.terminal.write(message)
#         self.log.write(message)

#     def flush(self):
#         self.terminal.flush()
#         self.log.flush()

#     def __del__(self):
#         if self.log is not None:
#                 self.log.close()

def _setup_analysis_logger(function_name: str, log_dir: str, debug: bool = False, to_console: bool = True) -> logging.Logger:
    """
    为特定的函数分析任务配置并返回一个独立的日志记录器。
    日志将同时写入文件和控制台（如果 to_console 为 True）。
    文件日志包含完整前缀，控制台日志不包含前缀。
    """
    # Ensure the log directory exists
    os.makedirs(log_dir, exist_ok=True)
    log_file_path = os.path.join(log_dir, f'{function_name}.log')

    # Get or create the logger instance named after the function
    logger = logging.getLogger(function_name)

    # Clear any existing handlers to prevent duplicate output
    if logger.hasHandlers():
        logger.handlers.clear()

    # Set the logger's overall level
    logger.setLevel(logging.DEBUG if debug else logging.INFO)
    
    # Prevent propagation to the root logger to avoid duplicate output
    logger.propagate = False

    # --- Formatter for File Output (with prefix) ---
    file_formatter = logging.Formatter('%(asctime)s - %(levelname)s  - %(message)s')

    # --- Formatter for Console Output (no prefix) ---
    console_formatter = logging.Formatter('%(message)s') # Only the message, no prefix

    # 1. Add File Handler
    file_handler = logging.FileHandler(log_file_path, mode='w', encoding='utf-8')
    file_handler.setLevel(logging.DEBUG if debug else logging.INFO) # File gets all debug info if debug_mode is on
    file_handler.setFormatter(file_formatter) # Use the file-specific formatter
    logger.addHandler(file_handler)

    # 2. Add Console Handler (if enabled)
    if to_console:
        console_handler = logging.StreamHandler(sys.stdout)
        # Console usually gets INFO level and above for clarity
        console_handler.setLevel(logging.INFO) 
        console_handler.setFormatter(console_formatter) # Use the console-specific formatter
        logger.addHandler(console_handler)

    return logger


class FunctionProcessor:
    """函数处理主类"""
    
    def __init__(self, config: CodeAnalyzerConfig) -> None:
        """主处理器构造函数
        
        参数:
            config (CodeAnalyzerConfig): 分析器配置对象
        
        异常:
            ValueError: 当输入配置不合法时抛出
        """
        if not isinstance(config, CodeAnalyzerConfig):
            raise ValueError("Invalid config type")
    
        self.config = config
        self.global_type_info_dict: Dict = {}
        self.tu_dict: Dict = {}
        self.file_cache: Dict = {}
        self.function_info_list: List[FunctionInfo] = []
        self.pending_functions: List[str] = []
        self.top_function_info = None
        self.config.input_path = os.path.join(self.config.input_dir,self.config.root_dir.split('/')[-1])
        self.config.annotated_c_file_path= os.path.join(self.config.annotated_c_dir,self.config.root_dir.split('/')[-1])
        self.config.annotated_loop_c_file_path = os.path.join(self.config.annotated_loop_dir,self.config.root_dir.split('/')[-1])
        self.config.generated_loop_c_file_path =  os.path.join(self.config.generated_loop_dir,self.config.root_dir.split('/')[-1])
        self.config.output_path = os.path.join(self.config.output_dir,self.config.root_dir.split('/')[-1])

        # 创建日志目录
        os.makedirs(self.config.log_dir, exist_ok=True)

        # 初始化双路输出
        self.logger = _setup_analysis_logger(
                function_name=self.config.function_name,
                log_dir=self.config.log_dir, 
                debug=self.config.debug, 
                to_console=True 
            )
        # 初始化工作目录

        if self.config.pre_process:
            self.logger.info("\nPREPROCESS WORKDIR")
            self.logger.info('='* 40+'\n')
            self._prepare_workspace()

    def _prepare_workspace(self):
        """预处理工作目录（宏处理）"""
      
        process_all_c_files(self.config.root_dir,self.config.input_path)
        

    def _initialize_function(self, func_name: str) -> FunctionInfo:
        """初始化单个函数信息"""
       
        return function_info_init(
            self.tu_dict,
            self.config.input_path,
            func_name,
            self.file_cache,
            self.global_type_info_dict
        )
    
    


    def _process_new_function(self, func_name: str):
        """处理新发现的函数"""
        self.logger.info(f'现在处理函数 {func_name}\n')

        new_func = self._initialize_function(func_name)

        self.function_info_list.append(new_func)
        self.pending_functions.append(func_name)
        self.pending_functions.extend(new_func.callee_set)

    def _generate_annotations(self, func: FunctionInfo):
        """生成函数注释和后置条件"""
        self.logger.info(f'开始生成 {func.name} 的注释代码')

        create_generated_c_file(
            func,
            self.config.generated_loop_c_file_path,
            self.config.debug
            )

        if self.config.auto_annotation:
            create_annotated_c_file(
                    func,
                    self.function_info_list,
                    self.config.annotated_c_file_path,
                    self.config.annotated_loop_c_file_path,
                    self.global_type_info_dict,
                    self.config.debug
            )

        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, func.code))

        if matches:
            self.logger.info(f"\nGENERATE LOOP INVARIANT FOR {func.name}")
            self.logger.info('='* 40+'\n')
            generator = InvGenerator(self.config,func,self.logger)
            generator.run()

        # 后置条件生成（根据需要启用）
        self.logger.info(f"\nGENERATE FUNCTION SUMMARY FOR {func.name}")
        self.logger.info('='* 40+'\n')
        post_cond = create_post(func.name,self.config.annotated_loop_c_file_path)
        # print(post_cond)
        if post_cond != 'SymExec Failed':
            postcond_list = refine_postcond(post_cond)
            func.annotation = update_annotation(func.annotation, postcond_list)
            self.logger.info(f'开始生成完整的 {func.name} 的注释代码')
            create_final_c_file(
                func,
                self.function_info_list,
                self.config.annotated_loop_c_file_path,
                self.global_type_info_dict,
                self.config.debug
            )
            self.logger.info(f'开始生成 {func.name} 的 ACSL 规约')
            create_specification(
                func,
                self.function_info_list,
                self.config.generated_loop_c_file_path,
                self.config.output_path,
                self.global_type_info_dict,
                self.config.debug
                )
        
        else:
            self.logger.info(f'开始生成 {func.name} 的 ACSL 规约')
            create_specification_by_llm(
                func,
                self.function_info_list,
                self.config.generated_loop_c_file_path,
                self.config.output_path,
                self.global_type_info_dict,
                self.config.debug
            )

        

    def verify(self):
        self._verify()

    def run_analysis(self):
        """执行分析主流程"""
        # 初始化入口函数
    
        self.logger.info("\nFUNCTION INITIALIZATION")
        self.logger.info('='* 40+'\n')
        
        main_func = self._initialize_function(self.config.function_name)
        self.function_info_list.append(main_func)
        self.pending_functions = [main_func.name, *main_func.callee_set]
        self.logger.info(f"初始待处理函数: {self.pending_functions}")

        # 处理函数队列
        while self.pending_functions:
            current_func = self.pending_functions.pop()
            
            # 检查是否已初始化
            existing_func = next(
                (f for f in self.function_info_list if f.name == current_func),
                None
            )

            if existing_func:
                self._handle_existing_function(existing_func)

            else:
               
                self._process_new_function(current_func)

        # 输出结果并清理
        self._finalize()
        self._verify()

        if self.config.generlization:
            self.__generalization()
        

    def _handle_existing_function(self, func: FunctionInfo):
        """处理已初始化函数"""

        self.logger.info(f"\nGENERATE ANNOTATION FOR {func.name}")
        self.logger.info('='* 40+'\n')

        self.logger.info(f'函数 {func.name} 已经初始化')
        if not func.annotation:
            self._generate_annotations(func)
            
        self.function_info_list.append(func)

    def __generalization(self):
        self.logger.info(f"\nGENERLIZATION FOR {self.config.function_name}")
        self.logger.info('='* 40+'\n')
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )
        convertor = SpecificationConvertor(main_func)
        if convertor.z3_map:
            post2DSL = Post2DSL(main_func.specification,convertor.z3_map,self.config,self.logger)
            self.logger.info(f'\n{self.config.function_name} 的最大非冗余集合:')
            self.logger.info(post2DSL.D)

    def _finalize(self):
        """最终处理与清理"""
        # 获取主函数结果
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )

        self.logger.info(f"\nSUMMARY FOR {self.config.function_name}")
        self.logger.info('='* 40+'\n')

        self.logger.info(f'\n函数 {self.config.function_name} 的 VST Summary 为:\n{main_func.annotation}')
        self.logger.info(f'\n函数 {self.config.function_name} 的 ACSL Summary 为:\n{main_func.specification}')
        
        free_all_tu(self.tu_dict)
        


    def _verify(self):
        self.logger.info(f"\nVERIFICATION FOR {self.config.function_name}")
        self.logger.info('='* 40+'\n')

        verifier = SpecVerifier(self.config,self.logger)
        verifier.run(self.config.function_name)   # 传入完整路径

      

# 使用示例
if __name__ == '__main__':
    # 配置参数
    config = CodeAnalyzerConfig(
        root_dir='1_input/test_ip',
        function_name='Fun',
        pre_process= False,
        auto_annotation= True,
        debug = True,
        generlization = True
    )
    
    # 执行分析
    processor = FunctionProcessor(config)
    processor.run_analysis()
