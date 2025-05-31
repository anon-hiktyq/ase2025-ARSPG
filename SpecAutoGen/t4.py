import re

# Assuming this code is part of a class, similar to your original example
class LoopAnalyzer:
    def __init__(self, data, var_maps):
        self.data = data
        self.var_maps = var_maps # Assuming var_maps is a list of dictionaries

    def get_json_at_index(self):
        # Placeholder method: Replace with your actual logic to get loop data
        # from self.data based on an index.
        # For demonstration, let's assume it returns a dict with 'content'.
        # Example:
        # return self.data[some_index]
        # For this example, we'll use a dummy structure:
        return {"content": "x = 10\ny = x + 5\nz = 20\nx += 1\nprint(y)\n# z is set but not used on the right"}

    def find_non_inductive_assignments(self):
        """
        找出所有"非归纳赋值"行：即某一行变量只做左值，且右侧没有用到自己。
        返回：
            List[Tuple[变量名, 行号, 行内容]]
        """
        loop = self.get_json_at_index()
        loop_content = loop.get("content", "")
        if not loop_content:
            return []
        if not self.var_maps or not isinstance(self.var_maps[0], dict):
            print("Warning: var_maps[0] is missing or not a dictionary.")
            return []
        var_map = self.var_maps[0]
        var_names = set(var_map.keys())
        results = []
        lines = loop_content.split('\n')
        for idx, line in enumerate(lines, 1):
            for var in var_names:
                # 匹配简单赋值（如 a = ...），不包括 +=、-=、*=、/=、++、--
                m = re.match(rf"\s*{re.escape(var)}\s*=(?!=)", line)
                if m:
                    # 取等号右侧
                    right_side = line.split('=', 1)[1]
                    # 检查右侧是否用到自己
                    if not re.search(rf"\b{re.escape(var)}\b", right_side):
                        results.append((var, idx, line.strip()))
        return results

# --- Example Usage ---
# Create a dummy instance of the class
analyzer = LoopAnalyzer(data=[{}], var_maps=[{"x": 0, "y": 0, "z": 0, "a": 0}])

# Run the new method
non_inductive = analyzer.find_non_inductive_assignments()
print(f"Non-inductive assignments: {non_inductive}")

# Example with different content:
analyzer_2 = LoopAnalyzer(data=[{}], var_maps=[{"count": 0, "total": 0, "avg": 0}])
analyzer_2.get_json_at_index = lambda: {"content": "count = count + 1\ntotal += count\navg = total / count"}
non_inductive_2 = analyzer_2.find_non_inductive_assignments()
print(f"Non-inductive assignments (Example 2): {non_inductive_2}")

analyzer_3 = LoopAnalyzer(data=[{}], var_maps=[{"i": 0, "result": 0, "temp": 0, "flag": False}])
analyzer_3.get_json_at_index = lambda: {"content": "i ++ \nresult = i * 2\nflag = True\n# temp is set but not used elsewhere\ntemp = 100"}
non_inductive_3 = analyzer_3.find_non_inductive_assignments()
print(f"Non-inductive assignments (Example 3): {non_inductive_3}")