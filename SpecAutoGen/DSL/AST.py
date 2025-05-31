from z3 import *
import re

# --- AST Node Definitions ---
# AST nodes will now store the Z3 variable name strings

class ASTNode:
    def to_z3(self, current_vars, old_vars):
        raise NotImplementedError

class LogicalAnd(ASTNode):
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars):
        return And(self.left.to_z3(current_vars, old_vars), self.right.to_z3(current_vars, old_vars))

class Comparison(ASTNode):
    def __init__(self, operator, left, right):
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
            # Integer division
            return left_z3 / right_z3 # Z3's / is integer division for Ints
        else:
            raise ValueError(f"Unsupported arithmetic operator: {self.operator}")

class OldVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name # Store the Z3 variable name string

    def to_z3(self, current_vars, old_vars):
        # Look up the Z3 variable object using the stored name
        if self.z3_var_name in old_vars:
            return old_vars[self.z3_var_name]
        else:
            # This indicates an issue with the substitution or variable mapping
            raise KeyError(f"Z3 old variable '{self.z3_var_name}' not found in old_vars mapping.")

class CurrentVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name # Store the Z3 variable name string

    def to_z3(self, current_vars, old_vars):
        # Look up the Z3 variable object using the stored name
        if self.z3_var_name in current_vars:
            return current_vars[self.z3_var_name]
        else:
            # This indicates an issue with the substitution or variable mapping
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

# --- Basic Tokenizer (adjusted for substituted names) ---
def tokenize(text):
    tokens = []
    # Use regex to find known tokens. Order matters for operators like <= vs <
    token_patterns = [
        (r'\s+', None),           # Whitespace
        # Modified IDENTIFIER pattern to specifically capture Z3-style names like pIp_fabs_0, old_pIp_ret_v
        # It's important that this captures the full variable name without breaking it.
        (r'[a-zA-Z_][a-zA-Z0-9_]*', 'IDENTIFIER'), # General identifiers like pIp_fabs_0, old_pIp_ret_v
        (r'<=', 'LESS_EQ'),
        (r'>=', 'GREATER_EQ'),
        (r'<', 'LESS'),
        (r'>', 'GREATER'),
        (r'==', 'EQUAL'),
        (r'!=', 'NOT_EQUAL'),
        (r'\+', 'PLUS'),
        (r'-', 'MINUS'),
        (r'\*', 'STAR'),           # Arithmetic multiplication
        (r'/', 'SLASH'),
        (r'&&', 'AND'),
        (r'\(', 'LPAREN'),
        (r'\)', 'RPAREN'),
        (r'\d+', 'INT'),           # Integer constants
        (r'true', 'TRUE_LITERAL'),      # Boolean literal true
        (r'false', 'FALSE_LITERAL'),    # Boolean literal false
    ]
    
    # We should not validate token names this way, as they are internal labels.
    # The original check `if not re.fullmatch(r'[a-zA-Z_]\w*', name):` was incorrect.
    # Just build the regex pattern directly.
    token_regex = '|'.join(f'(?P<{name}>{pattern})' if name else pattern for pattern, name in token_patterns)

    for match in re.finditer(token_regex, text):
        kind = match.lastgroup
        value = match.group(0)
        if kind is not None and kind != 'None': # Only add if it's a named token
            tokens.append((kind, value))
    return tokens

# --- Basic Parser (adjusted for substituted names) ---
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
        # Start parsing from the lowest precedence (logical AND)
        return self.parse_logical_and()

    def parse_logical_and(self):
        left = self.parse_comparison()
        while self.peek()[0] == 'AND':
            operator = self.consume('AND')[1]
            right = self.parse_comparison()
            left = LogicalAnd(left, right)
        return left

    def parse_comparison(self):
        left = self.parse_arithmetic_expr()
        # Use token kinds for comparison operators
        while self.peek()[0] in ['LESS_EQ', 'GREATER_EQ', 'LESS', 'GREATER', 'EQUAL', 'NOT_EQUAL']:
            kind, operator = self.consume()
            right = self.parse_arithmetic_expr()
            # Map token kind back to the operator string for the AST node
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
            # Handle unary minus - represents negation in arithmetic
            primary = self.parse_primary()
            return ArithmeticOperation('-', Constant(0), primary) # Represent as 0 - primary
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
            # Now identifiers are Z3 variable names (e.g., a_v, old_a_v)
            name = self.consume('IDENTIFIER')[1]
            # Determine if it's an old or current variable based on name format
            if name.startswith('old_'):
                # Store the Z3 variable name for the old variable
                return OldVariable(name)
            else:
                # Store the Z3 variable name for the current variable
                return CurrentVariable(name)
        else:
            raise SyntaxError(f"Unexpected token in primary expression: {token_kind} {token_value} at position {self.pos}")
        
# --- Substitution Function ---
def substitute_acsl_vars(text, sorted_regex_info):
    substituted_text = text
    for original_pattern_str, acsl_regex, z3_name in sorted_regex_info:
        substituted_text = acsl_regex.sub(z3_name, substituted_text)
    return substituted_text
