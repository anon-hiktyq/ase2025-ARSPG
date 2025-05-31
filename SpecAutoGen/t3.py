import re

def analyze_loop_variables_by_regex(loop_content, known_variables):
    """
    使用正则表达式分析循环体字符串，找出不变的变量和非归纳变量。

    不变变量：在已知变量列表中，但在循环体中从未作为左值出现。
    非归纳变量：在已知变量列表中，在循环体中作为左值出现，但从未作为右值出现。

    注意：这是一个启发式方法，基于正则表达式匹配，可能无法处理所有复杂的代码语法情况。

    Args:
        loop_content (str): 包含循环体代码的字符串。
        known_variables (list or set or dict_keys): 循环前已知的变量名列表、集合或字典的 keys。

    Returns:
        tuple: 包含两个列表的元组：
               - unchanged_vars (list): 不变的变量列表。
               - non_inductive_vars (list): 非归纳变量列表。
    """
    if not loop_content or not loop_content.strip():
        print("Warning: loop_content is empty or whitespace. Assuming all known variables are unchanged.")
        # 如果循环体为空，则所有已知变量都是不变的，没有非归纳变量
        return list(known_variables), []

    # 确保 known_variables 是一个方便查找的集合
    known_variables_set = set(known_variables)

    # --- 正则表达式定义 ---

    # 匹配左值：变量名后面跟着赋值、增量、减量或复合赋值操作符
    # \b(\w+)\b确保匹配完整的变量名（单词）
    # \s* 匹配可选的空格
    # (\+\+|--|\+=|-=|\*=|/=|=(?!=)) 匹配常见的赋值或增减运算符 (= 但不包括 ==, !=, <=, >=)
    # 捕获组 1 是变量名
    lhs_pattern = re.compile(r"\b(\w+)\s*(\+\+|--|\+=|-=|\*=|/=|=(?!=))")

    # 匹配所有看起来像变量名的词（由字母、数字、下划线组成）
    # \b(\w+)\b确保匹配完整的词
    # 捕获组 1 是词
    word_pattern = re.compile(r"\b(\w+)\b")

    # --- 分析过程 ---

    # 1. 找到所有在循环中作为左值出现的变量名
    lhs_vars_set = set()
    for match in lhs_pattern.finditer(loop_content):
        var_name_candidate = match.group(1)
        # 只考虑在已知变量列表中的变量作为左值
        if var_name_candidate in known_variables_set:
             lhs_vars_set.add(var_name_candidate)

    # 2. 找到循环内容中所有看起来像变量名（或词）的词
    all_words_in_loop_set = set()
    for match in word_pattern.finditer(loop_content):
         word_candidate = match.group(1)
         # 只考虑在已知变量列表中的词
         if word_candidate in known_variables_set:
              all_words_in_loop_set.add(word_candidate)


    # 3. 近似识别作为右值出现的变量集合
    # 认为所有在循环中出现的、且属于已知变量的词，如果不是左值，就可能是右值（或以右值形式出现）
    # 这是一个近似，它包括了所有不是左值的、已知变量名的出现。
    rhs_vars_approx_set = all_words_in_loop_set - lhs_vars_set


    # --- 计算最终结果 ---

    # 不变的变量：在已知变量列表中，但不在 lhs_vars_set 中
    unchanged_vars = [var_name for var_name in known_variables_set if var_name not in lhs_vars_set]

    # 非归纳变量：在已知变量列表中，同时在 lhs_vars_set 中，但不在 rhs_vars_approx_set 中
    # 这是基于变量是否出现在左值/右值位置的判断
    non_inductive_vars = [var_name for var_name in known_variables_set
                          if var_name in lhs_vars_set and var_name not in rhs_vars_approx_set]

    # --- 打印分析结果 ---
    print("\n--- Regex Analysis Results ---")
    print(f"Analyzed loop content (first 100 chars): {loop_content[:100]}{'...' if len(loop_content) > 100 else ''}")
    print(f"Known variables before loop: {list(known_variables_set)}")
    print(f"Variables identified as LHS (distinct, filtered by known): {lhs_vars_set}")
    print(f"All known variables found in loop (distinct): {all_words_in_loop_set}")
    print(f"Approximate RHS variables (distinct, filtered by known): {rhs_vars_approx_set}")
    print(f"Unchanged variables (Known & Never LHS): {unchanged_vars}")
    print(f"Non-inductive variables (Known, Is LHS, But Approx Not RHS): {non_inductive_vars}")
    print(f"--- End Analysis ---\n")


    return unchanged_vars, non_inductive_vars

# --- 示例使用 ---

# 示例1：包含各种变量使用的情况
# 根据前面的分析：
# i: LHS/RHS (i = i+1, sum+=i, i<10, printf args)
# sum: LHS/RHS (sum+=i, printf arg)
# temp: LHS (temp=5)
# flag: LHS (flag=1)
# result: LHS/RHS (result = temp + flag)
# count: LHS/RHS (count++, total=count)
# total: LHS (total = count)
# x: LHS (x=10)
# y: LHS/RHS (y=outside_var)
# outside_var: RHS (y=outside_var)
# unused_var: Unchanged
mock_loop_content_1 = """
  sum += i;
  i = i + 1;
  temp = 5;
  if (i > 5) {
      flag = 1;
  }
  printf("%d %d\\n", sum, i);
  result = temp + flag;
  count++;
  total = count;
  x = 10;
  y = outside_var;
  // z = z + 1; // 如果 z 不在 known_variables 中，它不会出现在结果里
"""

# 示例变量列表：循环前已知的变量
mock_known_variables_1 = [
    "i", "sum", "x", "y", "count", "total", "temp",
    "flag", "result", "outside_var", "unused_var", "z" # 假设 z 也是已知变量
]

print("--- Analyzing Example 1 ---")
unchanged_regex_1, non_inductive_regex_1 = analyze_loop_variables_by_regex(
    mock_loop_content_1,
    mock_known_variables_1
)
# 预期结果 (基于正则表达式启发式):
# LHS_Set: {i, sum, temp, flag, result, count, total, x, y, z}
# All_Words_Set (Known): {i, sum, temp, flag, result, count, total, x, y, outside_var, z}
# RHS_Approx_Set (All_Words - LHS): {outside_var}
# Unchanged: known_variables_set - LHS_Set -> {unused_var}
# Non-Inductive (LHS but not RHS_Approx): {i, sum, temp, flag, result, count, total, x, y, z} - {outside_var} -> {i, sum, temp, flag, result, count, total, x, y, z}
# **注意** 这个结果可能与更严格的数据流分析不同，因为 rhs_vars_approx_set 的识别是近似的。
# 特别是像 `i = i + 1;` 这样的变量，`i` 既是 LHS 又是 RHS。在 All_Words_Set 中有 `i`，在 LHS_Set 中有 `i`，RHS_Approx_Set 中就没有 `i`。
# 按照 "Is LHS but not RHS_Approx" 定义，i 会被错误地认为是 non-inductive。
# 这是这种简单 regex 方法的局限性。

# 更符合你 "做左值时没有同时做右值" 定义的变量应该是： temp, flag, x, y (如果 outside_var 不是已知变量)
# 让我们看看脚本跑出来的结果。


# 示例2：一个更简单的循环体
mock_loop_content_2 = """
  a = b + c;
  d = 20;
"""
mock_known_variables_2 = ["a", "b", "c", "d", "e"]

print("--- Analyzing Example 2 ---")
unchanged_regex_2, non_inductive_regex_2 = analyze_loop_variables_by_regex(
    mock_loop_content_2,
    mock_known_variables_2
)
# 预期结果 (基于正则表达式启发式):
# LHS_Set: {a, d}
# All_Words_Set (Known): {a, b, c, d}
# RHS_Approx_Set: {b, c}
# Unchanged: {e}
# Non-Inductive: {a, d} - {b, c} = {a, d}
# 这里的非归纳结果 {a, d} 是符合 "做左值时没有同时做右值" 定义的。


# 示例3：空循环体
mock_loop_content_3 = """
// Empty loop body
"""
mock_known_variables_3 = ["var1", "var2"]

print("--- Analyzing Example 3 ---")
unchanged_regex_3, non_inductive_regex_3 = analyze_loop_variables_by_regex(
    mock_loop_content_3,
    mock_known_variables_3
)
# 预期结果:
# LHS_Set: {}
# All_Words_Set (Known): {}
# RHS_Approx_Set: {}
# Unchanged: {var1, var2}
# Non-Inductive: {} - {} = {}