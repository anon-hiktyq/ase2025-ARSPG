
from MainProcessor import FunctionProcessor
from Config import CodeAnalyzerConfig
from SpecifactionVerify import SpecVerifier
import logging
import sys
import contextlib
import time
from io import StringIO

def setup_logging(log_file='result/frama-c_loop2.log'):
    """配置日志系统和输出重定向"""
    # 创建基础日志配置
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s [%(levelname)s] %(message)s',
        handlers=[
            logging.FileHandler(log_file, mode='w'),  # 覆盖模式
            logging.StreamHandler()  # 保留控制台输出
        ]
    )

    # 自定义输出流捕获器
    class LogRedirector:
        def __init__(self, logger, level):
            self.logger = logger
            self.level = level
            self.buffer = StringIO()

        def write(self, message):
            if message.strip():
                self.buffer.write(message)
                self.logger.log(self.level, message.strip())

        def flush(self):
            pass  # 不需要实际flush操作

    # 重定向标准输出和错误
    sys.stdout = LogRedirector(logging.getLogger('STDOUT'), logging.INFO)
    sys.stderr = LogRedirector(logging.getLogger('STDERR'), logging.ERROR)

@contextlib.contextmanager
def capture_analysis_output(func_name):
    """带函数名称的上下文管理器"""
    logger = logging.getLogger()
    try:
        logger.info(f"🟢 开始分析函数: {func_name}")
        yield
        logger.info(f"✅ 成功完成分析: {func_name}\n")
    except Exception as e:
        logger.error(f"🔴 分析失败 {func_name}: {str(e)}", exc_info=True)
        raise

def main():
    # 初始化日志配置
    setup_logging()
    
    # 函数列表 (示例数据)
    function_name_list = ['main28']
    
    #function_name_list = ['main14','main15','main16','main17']
    # function_name_list = ['test18']

    correct_count = 0
    total_time=0
    # 遍历所有函数
    for func_name in function_name_list:
        
        
        for t in range(1):
            
            with capture_analysis_output(func_name):
                start_time = time.time()
                # 创建配置实例
                config = CodeAnalyzerConfig(
                    root_dir='1_input/frama-c-loop',
                    function_name=func_name, 
                    pre_process=False,
                    auto_annotation=True
                )
                
                # 初始化处理器
                processor = FunctionProcessor(config)
                
                # 执行分析并捕获输出
                processor.run_analysis()  # 所有输出将自动记录到日志

                verifier = SpecVerifier(config)
                verifier.run(config.function_name)   # 传入完整路径
                
                validate_result = verifier.loop_result + verifier.post_result
                verify_result = verifier.assert_result
                syntax_error = verifier.syntax_error

                # 判断验证结果
                valid = bool(validate_result) and all(validate_result)
                # valid = all(validate_result)
                syntax = syntax_error ==''
                # satisfy = bool(verify_result) and all(verify_result)
                satisfy =  all(verify_result)
              
                if syntax and valid and satisfy:
                    print('正确规约')
                    file_time = time.time() - start_time
                    correct_count = correct_count + 1
                    total_time += file_time
                    print(f'TIME: {file_time}')

                    break
    
    print('正确个数：')
    print(correct_count)
    print('平均耗时: ')
    print(total_time/correct_count)
        
            

if __name__ == "__main__":
    main()