import re
from typing import List, Dict
from LoopInvGen.invGen import InvGenerator
# from target_program_init import function_init
from SpecAutoAnnotator.create_annotator import *
from SpecAutoAnnotator.create_post_condition import create_post, update_annotation
from SpecAutoAnnotator.extract_all import function_info_init
from SpecAutoAnnotator.main_class import *
from SpecAutoAnnotator.remove_macro import process_all_c_files
from SpecAutoAnnotator.refine_postcond import refine_postcond
from SpecifactionVerify import SpecVerifier
from Config import CodeAnalyzerConfig
from Convertor import SpecificationConvertor
from DSL.Q2D import Post2DSL



class FunctionProcessor:
    """函数处理主类"""
    
    def __init__(self, config: CodeAnalyzerConfig):
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
        
        # 初始化工作目录
        if self.config.pre_process:
            print("\nSTEP 1: PREPROCESS WORKDIR")
            print('='* 40+'\n')
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
        print(f'现在处理函数 {func_name}\n')

        new_func = self._initialize_function(func_name)

        self.function_info_list.append(new_func)
        self.pending_functions.append(func_name)
        self.pending_functions.extend(new_func.callee_set)

    def _generate_annotations(self, func: FunctionInfo):
        """生成函数注释和后置条件"""
        print(f'开始生成 {func.name} 的注释代码')

        create_generated_c_file(func,self.config.generated_loop_c_file_path)

        if self.config.auto_annotation:
            create_annotated_c_file(
                    func,
                    self.function_info_list,
                    self.config.annotated_c_file_path,
                    self.config.annotated_loop_c_file_path,
                    self.global_type_info_dict
            )

        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, func.code))

        if matches:
            print(f"\nSTEP 3.5: GENERATE LOOP INVARIANT FOR {func.name}")
            print('='* 40+'\n')
            generator = InvGenerator(self.config)
            generator.run(func)

        # 后置条件生成（根据需要启用）
        print(f"\nSTEP 4: GENERATE FUNCTION CONSTRACTION FOR {func.name}")
        print('='* 40+'\n')
        post_cond = create_post(func.name,self.config.annotated_loop_c_file_path)
        print(post_cond)
        if post_cond != 'SymExec Failed':
            postcond_list = refine_postcond(post_cond)
            func.annotation = update_annotation(func.annotation, postcond_list)
            print(f'开始生成完整的 {func.name} 的注释代码')
            create_final_c_file(
                func,
                self.function_info_list,
                self.config.annotated_loop_c_file_path,
                self.global_type_info_dict
            )
            print(f'开始生成 {func.name} 的 ACSL 规约')
            create_specification(
                func,
                self.function_info_list,
                self.config.generated_loop_c_file_path,
                self.config.output_path,
                self.global_type_info_dict
                )
        
        else:
            print(f'开始生成 {func.name} 的 ACSL 规约')
            create_specification_by_llm(
                func,
                self.function_info_list,
                self.config.generated_loop_c_file_path,
                self.config.output_path,
                self.global_type_info_dict
            )

        

    def verify(self):
        self._verify()

    def run_analysis(self):
        """执行分析主流程"""
        # 初始化入口函数
    
        print("\nSTEP 2: FUNCTION INITIALIZATION")
        print('='* 40+'\n')
        
        main_func = self._initialize_function(self.config.function_name)
        self.function_info_list.append(main_func)
        self.pending_functions = [main_func.name, *main_func.callee_set]
        print(f"初始待处理函数: {self.pending_functions}")

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
        self.__generalization()
        

    def _handle_existing_function(self, func: FunctionInfo):
        """处理已初始化函数"""

        print(f"\nSTEP 3: GENERATE ANNOTATION FOR {func.name}")
        print('='* 40+'\n')

        print(f'函数 {func.name} 已经初始化')
        if not func.annotation:
            self._generate_annotations(func)
            
        self.function_info_list.append(func)

    def __generalization(self):
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )
        conv = SpecificationConvertor(main_func)
        if conv.vars_list:
            print(conv.vars_map)
            post2DSL = Post2DSL(main_func.specification,conv.vars_map)
            print(post2DSL.D)

    def _finalize(self):
        """最终处理与清理"""
        # 获取主函数结果
        main_func = next(
            f for f in self.function_info_list 
            if f.name == self.config.function_name
        )
        print(f"\nSTEP 5: SPECIFACTION FOR {self.config.function_name}")
        print('='* 40+'\n')

        print(f'\n函数 {self.config.function_name} 的 VST 规约为:\n{main_func.annotation}')
        print(f'\n函数 {self.config.function_name} 的 ACSL 规约为:\n{main_func.specification}')



    def _verify(self):
        print(f"\nSTEP 6: VERIFICATION FOR {self.config.function_name}")
        print('='* 40+'\n')

        verifier = SpecVerifier(self.config)
        verifier.run(self.config.function_name)   # 传入完整路径

      

# 使用示例
if __name__ == '__main__':
    # 配置参数
    config = CodeAnalyzerConfig(
        root_dir='1_input/frama-c-loop',
        function_name='func8',
        pre_process= False,
        auto_annotation= True
    )
    
    # 执行分析
    processor = FunctionProcessor(config)
    processor.run_analysis()