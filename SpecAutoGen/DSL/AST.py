import re
from z3 import And, Int, Bool, Or, Solver, sat, unsat, Implies, ForAll, Exists


# --- AST Node Classes (Unchanged) ---
class ASTNode:
    def to_z3(self, current_vars, old_vars):
        raise NotImplementedError

class LogicalAnd(ASTNode):
    def __init__(self, left: ASTNode, right: ASTNode):
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        return And(self.left.to_z3(current_vars, old_vars), self.right.to_z3(current_vars, old_vars))

class LogicalOr(ASTNode):
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        return Or(self.left.to_z3(current_vars, old_vars), self.right.to_z3(current_vars, old_vars))

class LogicalImplication(ASTNode):
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        return Implies(self.left.to_z3(current_vars, old_vars), self.right.to_z3(current_vars, old_vars))

class Comparison(ASTNode):
    def __init__(self, operator: str, left: ASTNode, right: ASTNode):
        self.operator = operator
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        left_z3 = self.left.to_z3(current_vars, old_vars)
        right_z3 = self.right.to_z3(current_vars, old_vars)
        if self.operator == '<=':
            return left_z3 <= right_z3
        elif self.operator == '>=':
            return left_z3 >= right_z3
        elif self.operator == '<':
            return left_z3 < right_z3
        elif self.operator == '>':
            return left_z3 > right_z3
        elif self.operator == '==':
            return left_z3 == right_z3
        elif self.operator == '!=':
            return left_z3 != right_z3
        else:
            raise ValueError(f"Unsupported comparison operator: {self.operator}")

class ArithmeticOperation(ASTNode):
    def __init__(self, operator, left, right):
        self.operator = operator
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        left_z3 = self.left.to_z3(current_vars, old_vars)
        right_z3 = self.right.to_z3(current_vars, old_vars)
        if self.operator == '+':
            return left_z3 + right_z3
        elif self.operator == '-':
            return left_z3 - right_z3
        elif self.operator == '*':
            return left_z3 * right_z3
        elif self.operator == '/':
            return left_z3 / right_z3
        else:
            raise ValueError(f"Unsupported arithmetic operator: {self.operator}")

class OldVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name

    def to_z3(self, current_vars, old_vars):
        if self.z3_var_name in old_vars:
            return old_vars[self.z3_var_name]
        else:
            raise KeyError(f"Z3 old variable '{self.z3_var_name}' not found in old_vars mapping.")

class CurrentVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name

    def to_z3(self, current_vars, old_vars):
        if self.z3_var_name in current_vars:
            return current_vars[self.z3_var_name]
        else:
            raise KeyError(f"Z3 current variable '{self.z3_var_name}' not found in current_vars mapping.")

class Constant(ASTNode):
    def __init__(self, value):
        self.value = value

    def to_z3(self, current_vars, old_vars):
        return self.value

class BooleanLiteral(ASTNode):
    def __init__(self, value):
        self.value = bool(value)

    def to_z3(self, current_vars, old_vars):
        return self.value

class ForAllNode(ASTNode):
    def __init__(self, bound_vars, body):
        self.bound_vars = bound_vars
        self.body = body

    def to_z3(self, current_vars, old_vars):
        z3_bound_vars = []
        new_current_vars = current_vars.copy()
        
        for name, type_str in self.bound_vars:
            if type_str == 'integer':
                z3_var = Int(name)
                z3_bound_vars.append(z3_var)
                new_current_vars[name] = z3_var
            else:
                raise TypeError(f"Unsupported type '{type_str}' for quantified variable '{name}'")
        
        body_z3 = self.body.to_z3(new_current_vars, old_vars)
        
        return ForAll(z3_bound_vars, body_z3)

class ExistsNode(ASTNode):
    def __init__(self, bound_vars, body):
        self.bound_vars = bound_vars
        self.body = body

    def to_z3(self, current_vars, old_vars):
        z3_bound_vars = []
        new_current_vars = current_vars.copy()

        for name, type_str in self.bound_vars:
            if type_str == 'integer':
                z3_var = Int(name)
                z3_bound_vars.append(z3_var)
                new_current_vars[name] = z3_var
            else:
                raise TypeError(f"Unsupported type '{type_str}' for quantified variable '{name}'")
        
        body_z3 = self.body.to_z3(new_current_vars, old_vars)
        
        return Exists(z3_bound_vars, body_z3)


# --- Tokenizer (Unchanged) ---
def tokenize(text):
    tokens = []
    token_patterns = [
        (r'\s+', None),
        (r'\\forall', 'FORALL'),
        (r'\\exists', 'EXISTS'),
        (r'\b(integer|int)\b', 'TYPE_INTEGER'),
        (r'true', 'TRUE_LITERAL'),
        (r'false', 'FALSE_LITERAL'),
        (r'[a-zA-Z_][a-zA-Z0-9_]*', 'IDENTIFIER'),
        (r'==>', 'IMPLIES'),
        (r'<=', 'LESS_EQ'),
        (r'>=', 'GREATER_EQ'),
        (r'<', 'LESS'),
        (r'>', 'GREATER'),
        (r'==', 'EQUAL'),
        (r'!=', 'NOT_EQUAL'),
        (r'\+', 'PLUS'),
        (r'-', 'MINUS'),
        (r'\*', 'STAR'),
        (r'/', 'SLASH'),
        (r'&&', 'AND'),
        (r'\|\|', 'OR'),
        (r'\(', 'LPAREN'),
        (r'\)', 'RPAREN'),
        (r';', 'SEMICOLON'),
        (r',', 'COMMA'),
        (r'\d+', 'INT'),
    ]
    
    token_regex = '|'.join(f'(?P<{name}>{pattern})' if name else pattern for pattern, name in token_patterns)

    for match in re.finditer(token_regex, text):
        kind = match.lastgroup
        value = match.group(0)
        if kind is not None and kind != 'None':
            tokens.append((kind, value))
    return tokens

# --- Parser (Unchanged) ---
class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0

    def consume(self, expected_kind=None, expected_value=None):
        if self.pos < len(self.tokens):
            kind, value = self.tokens[self.pos]
            if (expected_kind is None or kind == expected_kind) and \
               (expected_value is None or value == expected_value):
                self.pos += 1
                return (kind, value)
            else:
                raise SyntaxError(f"Expected token kind {expected_kind} or value '{expected_value}' but found kind {kind} value '{value}' at position {self.pos}")
        else:
            raise EOFError("Unexpected end of tokens")

    def peek(self, offset=0):
        if self.pos + offset < len(self.tokens):
            return self.tokens[self.pos + offset]
        return (None, None)

    def parse_expression(self):
        return self.parse_quantifier()

    def parse_quantifier(self):
        token_kind, _ = self.peek()
        if token_kind in ('FORALL', 'EXISTS'):
            self.consume(token_kind)
            
            bound_vars = []
            while self.peek()[0] != 'SEMICOLON':
                self.consume('TYPE_INTEGER')
                var_type = 'integer'

                while True:
                    var_kind, var_name = self.consume('IDENTIFIER')
                    bound_vars.append((var_name, var_type))
                    if self.peek()[0] == 'COMMA':
                        self.consume('COMMA')
                    else:
                        break

            self.consume('SEMICOLON')
            
            body = self.parse_quantifier()

            if token_kind == 'FORALL':
                return ForAllNode(bound_vars, body)
            else: # 'EXISTS'
                return ExistsNode(bound_vars, body)

        return self.parse_implication()

    def parse_implication(self):
        left = self.parse_logical_or()
        if self.peek()[0] == 'IMPLIES':
            self.consume('IMPLIES')
            right = self.parse_implication()
            return LogicalImplication(left, right)
        return left

    def parse_logical_or(self):
        left = self.parse_logical_and()
        while self.peek()[0] == 'OR':
            self.consume('OR')
            right = self.parse_logical_and()
            left = LogicalOr(left, right)
        return left

    def parse_logical_and(self):
        left = self.parse_comparison()
        while self.peek()[0] == 'AND':
            self.consume('AND')
            right = self.parse_comparison()
            left = LogicalAnd(left, right)
        return left

    def parse_comparison(self):
        left = self.parse_arithmetic_expr()
        if self.peek()[0] in ['LESS_EQ', 'GREATER_EQ', 'LESS', 'GREATER', 'EQUAL', 'NOT_EQUAL']:
            kind, operator = self.consume()
            right = self.parse_arithmetic_expr()
            op_map = {'LESS_EQ': '<=', 'GREATER_EQ': '>=', 'LESS': '<', 'GREATER': '>', 'EQUAL': '==', 'NOT_EQUAL': '!='}
            left = Comparison(op_map[kind], left, right)
        return left

    def parse_arithmetic_expr(self):
        left = self.parse_term()
        while self.peek()[0] in ['PLUS', 'MINUS']:
            kind, operator = self.consume()
            right = self.parse_term()
            op_map = {'PLUS': '+', 'MINUS': '-'}
            left = ArithmeticOperation(op_map[kind], left, right)
        return left

    def parse_term(self):
        left = self.parse_factor()
        while self.peek()[0] in ['STAR', 'SLASH']:
            kind, operator = self.consume()
            right = self.parse_factor()
            op_map = {'STAR': '*', 'SLASH': '/'}
            left = ArithmeticOperation(op_map[kind], left, right)
        return left

    def parse_factor(self):
        token_kind, token_value = self.peek()
        if token_kind == 'LPAREN':
            self.consume('LPAREN')
            expression = self.parse_expression()
            self.consume('RPAREN')
            return expression
        elif token_kind == 'MINUS':
            self.consume('MINUS')
            primary = self.parse_primary()
            return ArithmeticOperation('-', Constant(0), primary)
        else:
            return self.parse_primary()

    def parse_primary(self):
        token_kind, token_value = self.peek()
        
        if token_kind == 'INT':
            value = int(self.consume('INT')[1])
            return Constant(value)
        elif token_kind == 'TRUE_LITERAL':
            self.consume('TRUE_LITERAL')
            return BooleanLiteral(True)
        elif token_kind == 'FALSE_LITERAL':
            self.consume('FALSE_LITERAL')
            return BooleanLiteral(False)
        elif token_kind == 'IDENTIFIER':
            name = self.consume('IDENTIFIER')[1]
            if name.startswith('old_'):
                return OldVariable(name)
            else:
                return CurrentVariable(name)
        else:
            raise SyntaxError(f"Unexpected token in primary expression: {token_kind} {token_value} at position {self.pos}")


# --- Helper functions (FIXED substitute_acsl_vars) ---
def substitute_acsl_vars(acsl_text, acsl_to_z3_sorted_map, debug):
    """
    Substitutes ACSL variable names with their corresponding Z3 names.
    This version correctly handles complex patterns like \old(x) and simple
    identifiers like x by using word boundaries conditionally.
    """
    substituted_text = acsl_text
    
    for acsl_name, z3_name in acsl_to_z3_sorted_map:
        if debug:
            print(f"Replacing '{acsl_name}' with '{z3_name}'")

        # --- MODIFIED LOGIC ---
        # If acsl_name is a simple identifier, use word boundaries for safe replacement.
        if re.fullmatch(r'[a-zA-Z_][a-zA-Z0-9_]*', acsl_name):
            pattern = r'\b' + re.escape(acsl_name) + r'\b'
        # Otherwise (for complex patterns like '\old(x)'), do a direct replacement.
        else:
            pattern = re.escape(acsl_name)
        
        substituted_text = re.sub(pattern, z3_name, substituted_text)
    
    return substituted_text

def get_z3_expr(acsl_to_z3_mapping_original, acsl_expr, current_vars, old_vars, debug):
    acsl_to_z3_mapping_original.sort(key=lambda item: len(item[0]), reverse=True)

    if debug:
        print("--- Sorted Replacement Map for Substitution ---")
        for acsl, z3_var in acsl_to_z3_mapping_original:
            print(f"  ACSL: '{acsl}' --> Z3: '{z3_var}'")
        print("---------------------------------------------")

    substituted_acsl_expression = substitute_acsl_vars(acsl_expr, acsl_to_z3_mapping_original, debug)
    
    if debug:
        print(f"Substituted ACSL Expression: {substituted_acsl_expression}")
    
    tokens = tokenize(substituted_acsl_expression)
    if debug:
        print(f"Tokens: {tokens}") 

    parser = Parser(tokens)
    ast = parser.parse_expression()
    z3_expr = ast.to_z3(current_vars, old_vars)

    print(f"Z3 Expression: {z3_expr}")
    if debug:
        print(f"Z3 Expression Type: {type(z3_expr)}")

    return z3_expr

# --- Example Usage (Unchanged) ---
if __name__ == '__main__':
    # --- Setup Z3 variables ---
    old_x = Int('old_x')
    old_y = Int('old_y')
    current_x = Int('x')
    current_y = Int('y')
    old_vars_map = {'old_x': old_x, 'old_y': old_y}
    current_vars_map = {'x': current_x, 'y': current_y}
    # IMPORTANT: The mapping for '\old(y)' must be sorted before 'y' to be replaced correctly.
    # The get_z3_expr function handles this sorting automatically.
    mapping = [
        (r'\old(x)', 'old_x'),
        (r'\old(y)', 'old_y'),
        ('x', 'x'),
        ('y', 'y'),
    ]

    print("--- Example 1: ForAll with 'integer' ---")
    acsl_forall_integer = r"\forall integer i; i > 10 ==> x > i"
    get_z3_expr(mapping, acsl_forall_integer, current_vars_map, old_vars_map, debug=False)
    print("\n" + "="*50 + "\n")

    print("--- Example 2: ForAll with 'int' ---")
    acsl_forall_int = r"\forall int i; i > 10 ==> x > i"
    get_z3_expr(mapping, acsl_forall_int, current_vars_map, old_vars_map, debug=False)
    print("\n" + "="*50 + "\n")
    
    # This example was the one that failed. It will now work correctly.
    print("--- Example 3: Exists with 'int' (Now Fixed) ---")
    acsl_exists = r"\exists int j; y == \old(y) * j && j > 1"
    get_z3_expr(mapping, acsl_exists, current_vars_map, old_vars_map, debug=False)
    # Expected Z3: Exists(j, And(y == old_y*j, j > 1))
    print("\n" + "="*50 + "\n")
    
    print("--- Example 4: Multiple bound variables with 'int' ---")
    acsl_multi_var = r"\forall int i, j; i > j ==> x + i > x + j"
    get_z3_expr(mapping, acsl_multi_var, current_vars_map, old_vars_map, debug=False)
    # Expected Z3: ForAll(i, j, Implies(i > j, x + i > x + j))
    print("\n" + "="*50 + "\n")