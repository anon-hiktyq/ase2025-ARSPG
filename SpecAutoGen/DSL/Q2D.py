import logging
from z3 import *
from .AST import *
from functools import lru_cache
from Config import CodeAnalyzerConfig
    

class Post2DSL:
    """
    A class to process postconditions, conceptually translating them into Z3 constraints.
    Currently, it generates generic range constraints for demonstration.
    """

    def __init__(self, acsl_ensures_string: str, variables_list: list, config: CodeAnalyzerConfig,logger:logging.Logger) -> None:
        """
        后置条件转换器初始化方法

        参数:
            acsl_ensures_string (str): ACSL格式的ensures条款字符串
            variables_list (list): 变量映射列表，包含Z3变量定义
        """
        
        # Store the ACSL ensures string. In a full implementation, this would be parsed.
        self.ensures_string = acsl_ensures_string
        
        # Store the Z3 variables that the postcondition operates on.

        self.variables_list = variables_list
        self.config = config
        self.logger = logger

        # [('old_a_v', '*\\\\old(a)'), ('a_v', '*a'), ('old_b_v', '*\\\\old(b)'), ('b_v', '*b'), ('old_r_v', '*\\\\old(r)'), ('r_v', '*r')]

        self.current_vars_z3 = {v[1]: BitVec(v[1],32) for v in variables_list if not v[1].startswith('old')} 
        # print('current_vars_z3')
        # print(self.current_vars_z3)
        # Map z3_name (a_v) to Z3 object
        self.old_vars_z3 = {v[1]: BitVec(v[1],32) for v in variables_list if v[1].startswith('old') } 
        # Map old_z3_name (old_a_v) to Z3 object
        # print('old_vars_z3')
        # print(self.old_vars_z3)
        self.variables = set(self.current_vars_z3.values()) | set(self.old_vars_z3.values())
       
       
        
        # Generate initial constraints. This method is now part of the class.
        # This currently generates generic range constraints;
        # actual parsing of self.ensures_string would happen here or in a separate method.
        self.C = self._generate_constraints_ip()
        

        self.Q = self._generate_ensures()

        self.D = self.compute_non_redundant(self.Q,self.C)
        
        # Placeholder for potential external client initialization (e.g., OpenAI)
        # self.openai_client = None 

    def _generate_constraints_1(self) -> list:
        
        # Use a unique placeholder variable name to avoid conflicts
        placeholder_var = BitVec('__z3_placeholder_var__',32)

        # Define template Z3 expressions using the placeholder
        template_expressions = [placeholder_var > i for i in range(-20, 20)] + \
                               [placeholder_var < i for i in range(-20, 20)]
        
        
        all_generated_constraints = []
        
        # Iterate through each variable provided during initialization and substitute it into the templates
        for current_var in self.variables:
            # Create a substitution map: replace the placeholder with the current Z3 variable
            substitution_map = [(placeholder_var, current_var)]
            
            # Apply the substitution to each template expression
            for template_expr in template_expressions:
                substituted_expr = substitute(template_expr, substitution_map)
                all_generated_constraints.append(substituted_expr)
                
        return all_generated_constraints
    

    def _generate_constraints_2(self) -> list:
        
        # Use unique placeholder variables
        placeholder_var_1 = BitVec('__z3_placeholder_var_1__',32)
        placeholder_var_2 = BitVec('__z3_placeholder_var_2__',32)

        # Template expression: v1 > v2
        template_expression_1 = placeholder_var_1 == placeholder_var_2
        

        all_generated_constraints = []

        # Generate all ordered pairs of variables (v1, v2) where v1 ≠ v2
        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' in str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_1, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        return all_generated_constraints

    
    def _generate_constraints_3(self) -> list:
        
        # Use unique placeholder variables
        placeholder_var= BitVec('__z3_placeholder_var__',32)

        # Template expression: v1 > v2
        template_expression = placeholder_var >= 0
      

        all_generated_constraints = []

        # Generate all ordered pairs of variables (v1, v2) where v1 ≠ v2
        for v in self.variables:
                    # Create substitution map
                    substitution_map = [
                        (placeholder_var, v)
                    ]
                    substituted_expr = substitute(template_expression, substitution_map)
                    all_generated_constraints.append(substituted_expr)

        return all_generated_constraints
    
    
    

    def _generate_constraints_ip(self) -> list:
       
        # Use unique placeholder variables
        placeholder_var_1 = BitVec('__z3_placeholder_var_1__',32)
        placeholder_var_2 = BitVec('__z3_placeholder_var_2__',32)

        template_expression_1 = placeholder_var_1 == placeholder_var_2
        template_expression_2 = placeholder_var_1 == 0
        template_expression_3 = placeholder_var_1 >= 0
        template_expression_4 = placeholder_var_1 <= 0
        template_expression_5 = placeholder_var_1 == 1
        template_expression_6 = placeholder_var_1 > placeholder_var_2
        template_expression_7 = placeholder_var_1 < placeholder_var_2
        


        all_generated_constraints = []

        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' in str(v2) and str(v1) in str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_6, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' in str(v2) and str(v1) in str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_7, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        # Generate all ordered pairs of variables (v1, v2) where v1 ≠ v2
        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' in str(v2) and str(v1) in str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_1, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' not in str(v2) and str(v1) != str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_1, substitution_map)
                        all_generated_constraints.append(substituted_expr)                

        for v1 in self.variables:
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                        ]
                        substituted_expr = substitute(template_expression_2, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        for v1 in self.variables:
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                        ]
                        substituted_expr = substitute(template_expression_3, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        for v1 in self.variables:
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                        ]
                        substituted_expr = substitute(template_expression_4, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        for v1 in self.variables:
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                        ]
                        substituted_expr = substitute(template_expression_5, substitution_map)
                        all_generated_constraints.append(substituted_expr)


        return all_generated_constraints
    

    def _generate_constraints_5(self) -> list:
       
        # Use unique placeholder variables
        placeholder_var_1 = BitVec('__z3_placeholder_var_1__',32)
        placeholder_var_2 = BitVec('__z3_placeholder_var_2__',32)

        # Template expression: v1 > v2
        template_expression_1 = placeholder_var_1 >=  Abs(placeholder_var_2)
        

        all_generated_constraints = []

        # Generate all ordered pairs of variables (v1, v2) where v1 ≠ v2
        for v1 in self.variables:
            if 'old' not in str(v1):
                for v2 in self.variables :
                    if 'old' in str(v2):
                    
                    # Create substitution map
                        substitution_map = [
                            (placeholder_var_1, v1),
                            (placeholder_var_2, v2)
                        ]
                        substituted_expr = substitute(template_expression_1, substitution_map)
                        all_generated_constraints.append(substituted_expr)

        return all_generated_constraints
    

     
    def _generate_ensures(self):
        # This list will store tuples: (z3_replacement_name, compiled_regex, original_acsl_pattern_string)
    
        Q = []

        # Extract ensures clauses
        ensures_start_index = self.ensures_string.find('ensures')
        if ensures_start_index == -1:
            ensures_clauses = []
        else:
            clauses_raw = self.ensures_string[ensures_start_index:].split('ensures')[1:]
            ensures_clauses = []
            for clause_raw in clauses_raw:
                next_comment_start = clause_raw.find('/*@')
                if next_comment_start == -1:
                    clause_content = clause_raw.strip()
                else:
                    clause_content = clause_raw[:next_comment_start].strip()

                if clause_content:
                    if clause_content.endswith(';'):
                        clause_content = clause_content[:-1].strip()
                    if clause_content.endswith('*/'):
                        clause_content = clause_content[:-2].strip()
                    ensures_clauses.append(clause_content)

        for clause in ensures_clauses:
            # Use the refined substitution logic
                # print(self.current_vars_z3)
                # print(clause)
                z3_expr = get_z3_expr(self.variables_list,clause,self.current_vars_z3,self.old_vars_z3,self.logger,self.config.debug)
                # print(z3_expr)
                Q.append(z3_expr)

          
        
        return Q
    


    def compute_non_redundant(self, Q, C) -> list:
        """
        计算非冗余约束集合

        参数:
            Q: 确保条件集合
            C: 原始约束集合

        返回:
            list: 精简后的非冗余约束集合
        """

        def entails(formulas, clause):
            s = Solver()
            for f in formulas:
                s.add(f)
            s.add(Not(clause))
            return s.check() == unsat
    
        def extract_literals(clause: BoolRef):
            """
            将一个 BoolRef 子句拆成它的“字面量”列表：
            - 如果它是一个 OR(a, b, c...)，就返回 [a, b, c, ...]
            - 否则当作单字面量返回 [clause]
            """
            return list(clause.children()) if is_or(clause) else [clause]
        
        # 1. 筛出所有 Q ⇒ c 的子句
        E = [c for c in C if entails(Q, c)]
       

        # 2. 给每个子句分配一个简单整数 ID
        clause_map = {i: c for i, c in enumerate(E)}
        
        def make_key(id_list):  
            return tuple(sorted(id_list))

        # 3. 启发式排序：按字面量数量降序（长子句先处理）
        E_ids = list(clause_map.keys())
        E_ids.sort(key=lambda i: len(extract_literals(clause_map[i])), reverse=True)

        D_ids = []  # 当前保留的子句集合

        @lru_cache(maxsize=None)
        def entails_cached(others_key, c_id):
            """
            缓存  { clause_map[i] for i in others_key } ⊨ clause_map[c_id] 的结果
            """
            others = [clause_map[i] for i in others_key]
            return entails(others, clause_map[c_id])

        @lru_cache(maxsize=None)
        def entails_single(c1_id, c2_id):
            """
            缓存单子句推导关系: clause_map[c1_id] ⊨ clause_map[c2_id]
            """
            return entails([clause_map[c1_id]], clause_map[c2_id])

        # 4. 贪心挑选 + 删除被反推的已有子句
        for cid in E_ids:

            key = make_key(D_ids)
            if entails_cached(key, cid):
                # 当前子句 c 已经可以被已有 D_ids 推导，跳过
                continue

            # 新子句可能能反推已有子句，删除那些冗余的
            to_remove = []
            for did in D_ids:
                if entails_single(cid, did):
                    to_remove.append(did)
            
            for did in to_remove:
                D_ids.remove(did)

            # 把当前 cid 加入 D_ids
            D_ids.append(cid)

        return [clause_map[i] for i in D_ids]

# --- Example Usage ---


if __name__ == "__main__":

    acsl_ensures_string = """
    /*@

    ensures (pIp->fabs[1] > 6 && -pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==>  pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[1];

    ensures (pIp->fabs[1] > 6 && -pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==>  pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[1];

    ensures (-pIp->fabs[1] > 6 && -pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) &&  pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[1];

    ensures (-pIp->fabs[1] > 6 && -pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[1];

    ensures (-pIp->fabs[1] > 6 && pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[1];

    ensures (-pIp->fabs[1] > 6 && pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[1];

    ensures (pIp->fabs[1] > 6 && pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[1];

    ensures (pIp->fabs[1] > 6 && pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[1];

    ensures (pIp->fabs[0] > 6 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[0];

    ensures (-pIp->fabs[0] > 6 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[0];

    ensures (-pIp->fabs[0] > 6 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[0];

    ensures (pIp->fabs[0] > 6 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[0];

    ensures (pIp->fabs[0] > 6 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[0];

    ensures (-pIp->fabs[0] > 6 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[0];

    ensures (-pIp->fabs[0] > 6 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[0];

    ensures (pIp->fabs[0] > 6 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[0];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (pIp->fabs[2] > 6 && pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] > 6 && -pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == -pIp->fabs[2];

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[2] <= 6 && -pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[0] <= 6 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[0] <= 6 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[0] <= 6 && pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[0] <= 6 && pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[0] <= 6 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[0] <= 6 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[0] <= 6 && -pIp->fabs[2] <= -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[0] <= 6 && -pIp->fabs[2] <= pIp->fabs[0] && pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[0] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[1] <= 6 && pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[1] <= 6 && pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[1] <= 6 && pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[1] <= 6 && pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[1] <= 6 && -pIp->fabs[2] <= -pIp->fabs[1] && pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (-pIp->fabs[1] <= 6 && -pIp->fabs[2] <= -pIp->fabs[1] && -pIp->fabs[0] <= -pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] < 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == -pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[1] <= 6 && -pIp->fabs[2] <= pIp->fabs[1] && -pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

    ensures (pIp->fabs[1] <= 6 && -pIp->fabs[2] <= pIp->fabs[1] && pIp->fabs[0] <= pIp->fabs[1] && pIp->fabs[2] < 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] >= 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[1] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);
    */
    """

    #variables_list = [('pIp', '110', 'pIp'), ('pIp_fabs', '001', 'pIp->fabs'), ('pIp_tmax', '100', 'pIp->tmax'), ('pIp_ret_v', '100', '*pIp->ret'), ('pIp_ret_a', '100', 'pIp->ret')]

    variables_list = [('pIp_fabs_1','000','pIp->fabs[1]'),('pIp_fabs_2','000','pIp->fabs[2]'),('pIp_fabs_0','000','pIp->fabs[0]'),('pIp_fabs', '001', 'pIp->fabs'),('pIp_ret_a', '100', 'pIp->ret'),('pIp_tmax', '100', 'pIp->tmax'), ('pIp_ret_v', '100', '*pIp->ret'), ('pIp_ret_a', '100', 'pIp->ret')]

    # 4. Create an instance of the Post2DSL class.
    post_processor = Post2DSL(acsl_ensures_string=acsl_ensures_string, 
                            variables_list=variables_list)

    # 5. Access the generated constraints from the instance.
    C = post_processor.C
    Q = post_processor.Q
    D = post_processor.D

    # 6. Print the generated constraints for verification.
    print("--- Generated Z3 Constraints (C) ---")
    for expr in C:
        print(f"  {expr}")

    print("--- Generated Z3 Ensures (Q) ---")

    for item in Q:
        # Z3 expressions have a __str__ method that gives a prefix-like representation
        print(f"Q.append({item})")

    print("--- Generated DSL Ensures (D) ---")
    print(D)



