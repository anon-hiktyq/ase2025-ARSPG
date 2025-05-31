import re

def updated_condition_str(condition_str, predefined_vars):
    # 定义需要排除的关键字和量词
    EXCLUDED_KEYWORDS = {'exists', 'forall'}
    
    # 严格变量正则（匹配标准变量名）
    variable_pattern = r'(?<!\w)([a-zA-Z_]\w*)(?!\w)'
    
    # 提取所有候选变量
    candidates = set(re.findall(variable_pattern, condition_str))
    
    # 多级过滤
    new_vars = []
    for var in candidates:
        if (var not in predefined_vars and               # 不在预定义集合中
            var.lower() not in EXCLUDED_KEYWORDS and     # 不是关键字
            not var.lstrip('-').isdigit() and            # 不是数字
            not any(op in var for op in {'+', '-', '*', '/', '%'})  # 不含操作符
           ):
            new_vars.append(var)
    
    new_vars = sorted(new_vars)

    # 将新变量添加到exists声明中
    if not new_vars:
            return condition_str
        
        # 在exists后追加新变量
    if 'exists' in condition_str:
            # 提取已存在的变量
            exists_part = condition_str.split('exists')[1].split(',')[0]
            existing_vars = [v.strip() for v in exists_part.split() if v.strip()]
        
            
            # 添加新变量（不重复）
            vars_to_add = [v for v in new_vars if v not in existing_vars]
            if vars_to_add:
                # 在第一个exists后插入新变量
                parts = condition_str.split('exists', 1)
                
                updated_str = f"{parts[0]}exists {' '.join(vars_to_add)}{parts[1]}"
            else:
                updated_str = condition_str
    else:
            updated_str = f"exists {' '.join(new_vars)}, {condition_str}"
        
    
    return updated_str



    

# 测试用例
if __name__ == "__main__":
    test_expr = """
   exists retval_77, -997 < 0 && retval_77 == --997 && abbb < 0 && retval_70 == -a && 42 >= 0 && retval_64 == 42 && -42 < 0 && retval_56 == --42
    """
    known_vars = ['ab'] # 预定义变量
    new_vars = updated_condition_str(test_expr, known_vars)
    print(new_vars)
    
  
