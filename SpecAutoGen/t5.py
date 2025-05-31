import re

# 假设需要过滤的数组名列表
array_names = ["a_l_73", "k_55"]

def replace_quantifier(match):
    quantifier = match.group(1).strip()  # exists 或 forall
    variables = match.group(2).strip().split()  # 变量列表（如 ["a_l_73", "i_70", "j_69"]）
    # 过滤掉 array_names 中的变量
    filtered_vars = [var for var in variables if var not in array_names]
    # 如果过滤后无变量，返回空字符串（删除整个量词声明）
    if not filtered_vars:
        return ""
    # 格式化为 "\quantifier int var1, var2;"
    return f"\\{quantifier} int {', '.join(filtered_vars)}; "

# 正则表达式匹配 exists/forall 后的变量直到逗号或行尾
pattern = r"(exists|forall)\s+([a-zA-Z_@][\w@]*(?:\s+[a-zA-Z_@][\w@]*)*)\s*,?"

# 示例输入
input_str = """
exists a_l_73 i_70 j_69, i_70 >= n &&
forall k_55, 0 <= k_55 && k_55 < i_70 => a_l_73[k_55] == k_55
"""

# 执行替换并清理多余空格
result = re.sub(pattern, replace_quantifier, input_str)
result = re.sub(r'\s+([&=>])', r' \1', result)  # 合并逻辑符前的多余空格

print("替换后的结果：")
print(result)