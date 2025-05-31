from z3 import Ints

def make_z3_ints(variables):
    """
    根据 variables 动态创建 Z3 Int 变量并返回一个列表。
    
    参数:
      - variables: list of tuples, 每个 tuple 的第一个元素是变量名字符串
      - prefix_old: 如果为 True，则同时创建 old_ 前缀的变量
    
    返回:
      - 如果 prefix_old=False： [v1, v2, ...]
      - 如果 prefix_old=True： [v1, v2, ..., old_v1, old_v2, ...]
    """
    # 1. 提取变量名
    names = [v[0] for v in variables]
    
    # 2. 定义这一组 Z3 变量
    z3_vars = Ints(' '.join(names))
    
    # 3. 转成列表（z3_vars 本身是 tuple）
    result = list(z3_vars)
    
    old_result = list()
    # 同理定义一组 old_ 变量
    old_names = ['old_' + n for n in names]
    old_z3_vars = Ints(' '.join(old_names))
    old_result.extend(list(old_z3_vars))
    
    return result,old_result

# 测试
if __name__ == '__main__':
    variables = [('a_v', '100', '*a'), ('b_v', '100', '*b'), ('c_v', '100', '*c')]
    z3_list,z3_with_old = make_z3_ints(variables)
    print(z3_list)  
    # 输出类似 [a_v, b_v, c_v]
    
    print(z3_with_old)
    # 输出类似 [a_v, b_v, c_v, old_a_v, old_b_v, old_c_v]
