import re

def refine_return(text):
    # 定义正则表达式模式，支持负数、浮点数和十六进制数
    # 使用 re.sub 进行替换
    text = re.sub(f'\(Ez_val\s*(-?[.\d]+)\s*\)', r'\1', text)
    return re.sub(f'_\d+_pre', '', text)





def refine_path_condition(postcond: str) -> str:
    """删去多余的括号和Ez_val"""

    # new_conditions = []
    # group = postcond.split('&&')
    # group[0] = group[0].strip()
    # for condition in group[1:]:
    #     group[0] = group[0][1:]
    #     condition = condition.strip()
    #     condition = condition[0:-1]
    #     new_conditions.append(condition)
    # first_condition = group[0]
    # new_conditions.insert(0, first_condition)
    # new_postcond = ' && '.join(new_conditions)
    # 删去Ez_val
    new_postcond = re.sub(f'\(Ez_val\s*(-?[.\d]+)\s*\)', r'\1', postcond)
   # print(new_postcond)
    return new_postcond

def refine_postcond(postcond_list: list) -> list:
    for postcond in postcond_list:
        postcond['path_condition'] = refine_path_condition(postcond['path_condition'])
        postcond['return_value'] = refine_return(postcond['return_value'])
    return postcond_list


if __name__ == '__main__':
    postcond = '(exists retval_100, (((((((pair_a_v == pair_a_v) && (pair_b_v == pair_b_v)) && (retval_100 == (pair_a_v - pair_b_v))) && (pair_operation_v == 2)) && (pair_operation_v != 1)) && (pair == pair_addr)) && (((pair_a_v == (pair->a)) * (pair_b_v == (pair->b))) * (pair_operation_v == (pair->operation)))))'
    new_postcond = refine_path_condition(postcond)
    # 示例字符串
    input_text = "(Ez_val 0)."

    # 调用函数并打印结果
    output_text = refine_return(input_text)

    print(new_postcond)
    print(output_text)