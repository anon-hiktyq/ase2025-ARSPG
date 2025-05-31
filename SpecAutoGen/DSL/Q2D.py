from z3 import *
from AST import *
from functools import lru_cache

class Post2DSL:
    """
    A class to process postconditions, conceptually translating them into Z3 constraints.
    Currently, it generates generic range constraints for demonstration.
    """

    def __init__(self, acsl_ensures_string: str, variables_list: list):
        """
        Initializes the Post2DSL processor.

        Args:
            acsl_ensures_string (str): The ACSL 'ensures' clause string (e.g., "a > 0 && b < 10").
                                       Currently, this string is stored but not parsed into constraints.
            variables_list (list): A list of Z3 variables (e.g., Int('x')) relevant to the postcondition.
        """
        # Store the ACSL ensures string. In a full implementation, this would be parsed.
        self.ensures_string = acsl_ensures_string
        
        # Store the Z3 variables that the postcondition operates on.

        self.variables_list = variables_list

        self.current_vars_z3 = {v[0]: Int(v[0]) for v in variables_list} 
        # Map z3_name (a_v) to Z3 object
        self.old_vars_z3 = {f'old_{v[0]}': Int(f'old_{v[0]}') for v in variables_list} 
        # Map old_z3_name (old_a_v) to Z3 object
        self.variables = set(self.current_vars_z3.values()) | set(self.old_vars_z3.values())
        print(self.variables)
       
        
        # Generate initial constraints. This method is now part of the class.
        # This currently generates generic range constraints;
        # actual parsing of self.ensures_string would happen here or in a separate method.
        self.C = self._generate_constraints_4()

        self.Q = self._generate_ensures()

        self.D = self.compute_non_redundant(self.Q,self.C)
        
        # Placeholder for potential external client initialization (e.g., OpenAI)
        # self.openai_client = None 

    def _generate_constraints_1(self) -> list:
        """
        Generates a set of generic range constraints for the class's Z3 variables.
        
        These constraints serve as a placeholder for more complex logic that would
        typically parse the ACSL ensures string into specific Z3 expressions.
        For demonstration, it creates constraints like `-20 < var < 20`.

        Returns:
            list: A list of Z3 expressions representing the generated constraints.
        """
        # Use a unique placeholder variable name to avoid conflicts
        placeholder_var = Int('__z3_placeholder_var__')

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
        """
        Generates constraints of the form v1 > v2 for all variable pairs (v1, v2).

        These constraints serve as a placeholder for more complex logic that would
        typically parse the ACSL ensures string into specific Z3 expressions.

        Returns:
            list: A list of Z3 expressions representing the generated constraints.
        """
        # Use unique placeholder variables
        placeholder_var_1 = Int('__z3_placeholder_var_1__')
        placeholder_var_2 = Int('__z3_placeholder_var_2__')

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
        """
        Generates constraints of the form v1 > v2 for all variable pairs (v1, v2).

        These constraints serve as a placeholder for more complex logic that would
        typically parse the ACSL ensures string into specific Z3 expressions.

        Returns:
            list: A list of Z3 expressions representing the generated constraints.
        """
        # Use unique placeholder variables
        placeholder_var= Int('__z3_placeholder_var__')

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
    
    def _generate_constraints_4(self) -> list:
        """
        Generates constraints of the form v1 > v2 for all variable pairs (v1, v2).

        These constraints serve as a placeholder for more complex logic that would
        typically parse the ACSL ensures string into specific Z3 expressions.

        Returns:
            list: A list of Z3 expressions representing the generated constraints.
        """
        # Use unique placeholder variables
        placeholder_var_1 = Int('__z3_placeholder_var_1__')
        placeholder_var_2 = Int('__z3_placeholder_var_2__')

        # Template expression: v1 > v2
        template_expression_1 = placeholder_var_1 >= placeholder_var_2
        

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
    

    def _generate_constraints_5(self) -> list:
        """
        Generates constraints of the form v1 > v2 for all variable pairs (v1, v2).

        These constraints serve as a placeholder for more complex logic that would
        typically parse the ACSL ensures string into specific Z3 expressions.

        Returns:
            list: A list of Z3 expressions representing the generated constraints.
        """
        # Use unique placeholder variables
        placeholder_var_1 = Int('__z3_placeholder_var_1__')
        placeholder_var_2 = Int('__z3_placeholder_var_2__')

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
        # This list will store tuples: (original_acsl_pattern_string, compiled_regex, z3_replacement_name)
        acsl_to_z3_regex_info = []

        # --- IMPORTANT: Define substitution rules in order of specificity (longest/most complex first) ---
        # This helps prevent partial matches and ensures correct substitution for nested expressions.

        # 1. Handle complex `\old` expressions involving dereferences or array accesses
        #    Example: `\old(*pIp->ret)` -> `old_pIp_ret_v`
        #             `\old(pIp->fabs[1])` -> `old_pIp_fabs_1`

        # First, iterate to find mappings for ACSL structure members and array elements to their Z3 names
        # Create a reverse map for easy lookup: c_var_name_acsl_normalized -> z3_name (current & old)
        acsl_c_name_map = {}
        for z3_name, var_type_code, acsl_c_name_raw in self.variables_list:
            # Normalize ACSL C names for matching. E.g., 'pIp->fabs[0]' or 'pIp->ret'
            if '->' in acsl_c_name_raw:
                acsl_c_name_map[acsl_c_name_raw] = z3_name # Store the current Z3 name
            elif '[' in acsl_c_name_raw and ']' in acsl_c_name_raw:
                # For flattened names like 'pIp_fabs[0]', reconstruct the C form 'pIp->fabs[0]'
                match_flat_array = re.fullmatch(r'(pIp_[a-zA-Z_]+)\[(\d+)\]', acsl_c_name_raw)
                if match_flat_array:
                    struct_member_name = match_flat_array.group(1).replace('pIp_', '') # 'fabs'
                    index = match_flat_array.group(2) # '0'
                    reconstructed_acsl_c_name = f'pIp->{struct_member_name}[{index}]'
                    acsl_c_name_map[reconstructed_acsl_c_name] = z3_name
            # For simpler scalar names like 'pIp_tmax', 'pIp_ret_a' if they map directly to 'pIp->tmax'
            # Assuming 'pIp_tmax' maps to 'pIp->tmax' in original ACSL.
            elif acsl_c_name_raw.startswith('pIp_'):
                 struct_member_name = acsl_c_name_raw.replace('pIp_', '')
                 reconstructed_acsl_c_name = f'pIp->{struct_member_name}'
                 acsl_c_name_map[reconstructed_acsl_c_name] = z3_name


        # Add rules for `\old(original_acsl_expr)` where original_acsl_expr is like `*pIp->ret` or `pIp->fabs[0]`
        for acsl_c_name_original, z3_name_current in acsl_c_name_map.items():
            if z3_name_current.startswith('pIp_'): # Current variable
                # For `\old(original_acsl_expr)`
                old_z3_name = f'old_{z3_name_current}'
                # Only add if the 'old_' version exists in our variables_list (means it's relevant for old state)
                if old_z3_name in self.old_vars_z3:
                    # Escape the original ACSL pattern for regex, making sure '\old' is treated as literal
                    acsl_pattern_old_expr = r'\\old\(' + re.escape(acsl_c_name_original) + r'\)'
                    acsl_to_z3_regex_info.append((
                        acsl_pattern_old_expr,
                        re.compile(acsl_pattern_old_expr),
                        old_z3_name
                    ))

        # Add rules for `*pIp->ret`
        # This needs a special entry because `*pIp->ret` is often explicitly dereferenced in ACSL.
        # Assuming `pIp_ret_v` is the Z3 name for `*pIp->ret`
        if 'pIp_ret_v' in self.current_vars_z3:
            # The ACSL pattern for dereferenced pointer
            acsl_pattern_deref = r'\*pIp->ret' # Match literal `*`
            acsl_to_z3_regex_info.append((
                acsl_pattern_deref,
                re.compile(acsl_pattern_deref),
                'pIp_ret_v'
            ))

        # Add rules for `\old(*pIp->ret)` (if distinct from `\old(pIp->ret)` if `old_pIp_ret_v` is used)
        if 'old_pIp_ret_v' in self.old_vars_z3:
            # The ACSL pattern for old dereferenced pointer
            acsl_pattern_old_deref = r'\\old\(\*pIp->ret\)' # Match literal `\old(*pIp->ret)`
            acsl_to_z3_regex_info.append((
                acsl_pattern_old_deref,
                re.compile(acsl_pattern_old_deref),
                'old_pIp_ret_v'
            ))


        # 2. Add rules for current ACSL expressions (pIp->fabs[1], pIp->ret, pIp->tmax)
        # These should be processed after the complex `\old` forms but before simple variable names.
        for z3_name, var_type_code, acsl_c_name_raw in self.variables_list:
            if not z3_name.startswith('old_'): # Only current variables
                # Reconstruct ACSL C name if it's a flattened array element name like 'pIp_fabs_0'
                if var_type_code == '000': # It's an array element (e.g., pIp_fabs_0)
                    match_flat_array = re.fullmatch(r'(pIp_[a-zA-Z_]+)_(\d+)', z3_name) # Match `pIp_fabs_0`
                    if match_flat_array:
                        struct_member_name = match_flat_array.group(1).replace('pIp_', '') # 'fabs'
                        index = match_flat_array.group(2) # '0'
                        original_acsl_form = f'pIp->{struct_member_name}[{index}]'
                        acsl_to_z3_regex_info.append((
                            original_acsl_form,
                            re.compile(re.escape(original_acsl_form)),
                            z3_name
                        ))
                elif var_type_code == '100' and '->' in acsl_c_name_raw: # Scalar struct member like pIp->tmax, pIp->ret
                    acsl_to_z3_regex_info.append((
                        acsl_c_name_raw,
                        re.compile(re.escape(acsl_c_name_raw)),
                        z3_name
                    ))
                # Note: `pIp->ret` is likely already covered by the specific `*pIp->ret` if it maps to `pIp_ret_v`.
                # If `pIp_ret_a` maps to `pIp->ret` directly, this rule covers it.

        # 3. Add rules for simple `old_variable_name` matching to `old_Z3_variable_name`
        # This is for generic `\old(var_name)` where var_name is a simple (non-struct/array) variable.
        # Your input variables are all struct members or array elements, so this might not be strictly needed,
        # but it's good for robustness.
        # For simplicity, if `c_var_name_acsl` is like `pIp->ret`, then `\old(pIp->ret)` is handled by `acsl_pattern_old_expr` above.
        # If your `variables_list` had `('old_global_var', '100', '\\old(global_var)')`, this would be relevant.
        # Given your current `variables_list`, the earlier rules should cover `\old` effectively.

        # Sort all compiled regex objects by the length of their original pattern string in descending order.
        # This is crucial: ensures longer, more specific patterns are matched and replaced first.
        sorted_acsl_regex_info = sorted(acsl_to_z3_regex_info, key=lambda x: len(x[0]), reverse=True)

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
            clause_content_substituted = substitute_acsl_vars(clause, sorted_acsl_regex_info)

            # Split into precondition and postcondition
            parts = clause_content_substituted.split('==>')
            precondition_str_substituted = "true"
            postcondition_str_substituted = clause_content_substituted.strip()

            if len(parts) == 2:
                precondition_str_substituted, postcondition_str_substituted = [p.strip() for p in parts]
            elif len(parts) > 2:
                print(f"Warning: Skipping clause due to unexpected format (multiple '==>'): {clause}")
                continue

            try:
                # Tokenize and parse precondition
                precondition_tokens = tokenize(precondition_str_substituted)
                if precondition_str_substituted.lower() == "true" or not precondition_str_substituted.strip():
                    precondition_ast = BooleanLiteral(True)
                else:
                    parser = Parser(precondition_tokens)
                    precondition_ast = parser.parse_expression()

                z3_precondition = precondition_ast.to_z3(self.current_vars_z3, self.old_vars_z3)

                # Tokenize and parse postcondition
                postcondition_tokens = tokenize(postcondition_str_substituted)
                parser = Parser(postcondition_tokens)
                postcondition_ast = parser.parse_expression()
                z3_postcondition = postcondition_ast.to_z3(self.current_vars_z3, self.old_vars_z3)

                Q.append(Implies(z3_precondition, z3_postcondition))

            except (SyntaxError, EOFError, ValueError, KeyError) as e:
                print(f"Error translating clause (after substitution) '{clause_content_substituted}': {e}")
                print(f"Original clause: '{clause}'")
                print(f"Skipping this clause.")
                continue
        
        return Q
    


    def compute_non_redundant(self, Q, C):

        def entails(formulas, clause, timeout=2000):
            s = Solver()
            s.set('timeout', timeout)
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
        print(E)

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

ensures (pIp->fabs[2] <= 6 && pIp->fabs[2] > -pIp->fabs[0] && -pIp->fabs[0] > pIp->fabs[1] && pIp->fabs[2] >= 0 && pIp->fabs[1] >= 0 && pIp->fabs[0] < 0) ==> pIp->fabs[0] == \old(pIp->fabs[0]) && pIp->fabs[1] == \old(pIp->fabs[1]) && pIp->fabs[2] == \old(pIp->fabs[2]) && pIp->tmax == pIp->fabs[2] && pIp->ret == \old(pIp->ret) && *pIp->ret == \old(*pIp->ret);

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



