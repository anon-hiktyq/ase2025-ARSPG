import re

def find_annotation_before_function(content, func_content):
    """
    查找紧邻函数前的 /*@ */ 注释（中间无其他代码）
    
    参数:
        path (str): 文件路径
        func_content (str): 函数完整代码（含签名和函数体）
        
    返回:
        str: 注释内容（无 /*@ 和 */），若不存在则返回空字符串
    """
    # with open(path, 'r', encoding='utf-8') as f:
    #     content = f.read()
    
    
    # 匹配目标函数（直接作为字符串）
    func_pattern = re.escape(func_content.strip())
    func_match = re.search(func_pattern, content, re.DOTALL)
    if not func_match:
        return str()
    
    func_start = func_match.start()
    
    # 提取函数前的所有内容
    before_func = content[:func_start]
    print(before_func)
    
    annotation_match = re.search(
        r'.*(/\*@.*?\*/)\Z',  
        before_func.strip(), 
        flags=re.DOTALL
    )
 
    return annotation_match[0]

# 测试用例
if __name__ == "__main__":
    test_code = """
    /*@ 不匹配的注释 */
    
    /*@
      requires x > 0;
      ensures \\result == x;
    */
    int func(int x) {
        return x;
    }
    """
    

    
    # 目标函数内容
    target_func = '''
    int func(int x) {
        return x;
    }
'''
    
    # 调用函数
    annotation = find_annotation_before_function(test_code, target_func)
    print("提取的注释：")
    print(annotation)