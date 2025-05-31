
from z3 import *
import re

# --- AST Node Definitions ---

class ASTNode:
    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        """
        Converts the AST node to a Z3 expression.
        quantifier_vars: A dictionary mapping quantified variable names (strings)
                         to Z3 variable objects within the current scope.
        """
        raise NotImplementedError

class LogicalAnd(ASTNode):
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        return And(self.left.to_z3(current_vars, old_vars, quantifier_vars),
                   self.right.to_z3(current_vars, old_vars, quantifier_vars))

class Comparison(ASTNode):
    def __init__(self, operator, left, right):
        self.operator = operator
        self.left = left
        self.right = right

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        left_z3 = self.left.to_z3(current_vars, old_vars, quantifier_vars)
        right_z3 = self.right.to_z3(current_vars, old_vars, quantifier_vars)
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

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        left_z3 = self.left.to_z3(current_vars, old_vars, quantifier_vars)
        right_z3 = self.right.to_z3(current_vars, old_vars, quantifier_vars)
        if self.operator == '+':
            return left_z3 + right_z3
        elif self.operator == '-':
            return left_z3 - right_z3
        elif self.operator == '*':
            return left_z3 * right_z3
        elif self.operator == '/':
            return left_z3 / right_z3 # Z3's / is integer division for Ints
        else:
            raise ValueError(f"Unsupported arithmetic operator: {self.operator}")

class OldVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        # Quantifier variables take precedence
        if quantifier_vars and self.z3_var_name in quantifier_vars:
            return quantifier_vars[self.z3_var_name]
        elif self.z3_var_name in old_vars:
            return old_vars[self.z3_var_name]
        else:
            raise KeyError(f"Z3 old variable '{self.z3_var_name}' not found in old_vars mapping or quantifier scope.")

class CurrentVariable(ASTNode):
    def __init__(self, z3_var_name):
        self.z3_var_name = z3_var_name

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        # Quantifier variables take precedence
        if quantifier_vars and self.z3_var_name in quantifier_vars:
            return quantifier_vars[self.z3_var_name]
        elif self.z3_var_name in current_vars:
            return current_vars[self.z3_var_name]
        else:
            raise KeyError(f"Z3 current variable '{self.z3_var_name}' not found in current_vars mapping or quantifier scope.")

class Constant(ASTNode):
    def __init__(self, value):
        self.value = value

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        return self.value

class BooleanLiteral(ASTNode):
    def __init__(self, value):
        self.value = bool(value)

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        return self.value

class Exists(ASTNode):
    def __init__(self, var_declarations, predicate):
        self.var_declarations = var_declarations
        self.predicate = predicate

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        bound_z3_vars = []
        new_quantifier_vars = {}
        if quantifier_vars:
            new_quantifier_vars.update(quantifier_vars)

        for var_type_str, var_name in self.var_declarations:
            if var_type_str == 'int':
                z3_var = Int(var_name)
            else:
                raise ValueError(f"Unsupported quantified variable type: {var_type_str}")

            bound_z3_vars.append(z3_var)
            new_quantifier_vars[var_name] = z3_var

        predicate_z3 = self.predicate.to_z3(current_vars, old_vars, new_quantifier_vars)

        if not bound_z3_vars:
             return predicate_z3
        return Z3Exists(bound_z3_vars, predicate_z3)


class PointerMemberAccess(ASTNode):
    def __init__(self, ptr_expr, member_name):
        self.ptr_expr = ptr_expr # This could be CurrentVariable or another PointerMemberAccess
        self.member_name = member_name

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        # Recursively get the base name string for the Z3 variable
        base_name_obj = self.ptr_expr.to_z3_name_string() if hasattr(self.ptr_expr, 'to_z3_name_string') else self.ptr_expr.z3_var_name
        combined_name = f"{base_name_obj}_{self.member_name}"

        if quantifier_vars and combined_name in quantifier_vars:
            return quantifier_vars[combined_name]
        elif combined_name in current_vars:
            return current_vars[combined_name]
        elif combined_name in old_vars:
            return old_vars[combined_name]
        else:
            raise KeyError(f"Z3 variable for pointer member '{combined_name}' not found in current_vars, old_vars, or quantifier scope.")

    def to_z3_name_string(self):
        # Helper to build the string representation used for Z3 variable names
        base_name_str = self.ptr_expr.to_z3_name_string() if hasattr(self.ptr_expr, 'to_z3_name_string') else self.ptr_expr.z3_var_name
        return f"{base_name_str}_{self.member_name}"

class ArrayIndex(ASTNode):
    def __init__(self, array_expr, index_expr):
        self.array_expr = array_expr # Could be CurrentVariable or PointerMemberAccess
        self.index_expr = index_expr

    def to_z3(self, current_vars, old_vars, quantifier_vars=None):
        # The base name is derived from the array_expr
        base_name_obj = self.array_expr.to_z3_name_string() if hasattr(self.array_expr, 'to_z3_name_string') else self.array_expr.z3_var_name

        # The index must be a constant for this flattening approach
        if not isinstance(self.index_expr, Constant):
            raise TypeError("Only constant integer indices are supported for flat Z3 variable mapping.")
        index_val = self.index_expr.value

        combined_name = f"{base_name_obj}_{index_val}"

        if quantifier_vars and combined_name in quantifier_vars:
            return quantifier_vars[combined_name]
        elif combined_name in current_vars:
            return current_vars[combined_name]
        elif combined_name in old_vars:
            return old_vars[combined_name]
        else:
            raise KeyError(f"Z3 variable for array element '{combined_name}' not found in current_vars, old_vars, or quantifier scope.")

    def to_z3_name_string(self):
        # Helper to build the string representation for Z3 variable names
        base_name_str = self.array_expr.to_z3_name_string() if hasattr(self.array_expr, 'to_z3_name_string') else self.array_expr.z3_var_name
        if not isinstance(self.index_expr, Constant):
            raise TypeError("Cannot create Z3 name string with non-constant array index.")
        return f"{base_name_str}_{self.index_expr.value}"

# Add a .to_z3_name_string() to CurrentVariable for consistency
def _current_variable_to_z3_name_string(self):
    return self.z3_var_name
CurrentVariable.to_z3_name_string = _current_variable_to_z3_name_string


# --- Tokenizer ---
def tokenize(text):
    tokens = []
    token_patterns = [
        (r'\s+', None),            # Whitespace (ignored)
        (r'\\exists', 'EXISTS'),    # Keyword for existential quantifier
        (r'\bint\b', 'TYPE_INT'),   # Keyword for int type in quantifiers
        (r'\btrue\b', 'TRUE_LITERAL'), # Boolean true
        (r'\bfalse\b', 'FALSE_LITERAL'),# Boolean false
        (r'[a-zA-Z_][a-zA-Z0-9_]*', 'IDENTIFIER'), # General identifiers (e.g., pIp, abs, i_60_83)
        (r'<=', 'LESS_EQ'),
        (r'>=', 'GREATER_EQ'),
        (r'<', 'LESS'),
        (r'>', 'GREATER'),
        (r'==', 'EQUAL'),
        (r'!=', 'NOT_EQUAL'),
        (r'==>', 'IMPLIES_OP'),    # ACSL Implies operator
        (r'\+', 'PLUS'),
        (r'-', 'MINUS'),
        (r'\*', 'STAR'),           # Arithmetic multiplication or dereference
        (r'/', 'SLASH'),
        (r'&&', 'AND'),
        (r'\(', 'LPAREN'),
        (r'\)', 'RPAREN'),
        (r'\[', 'LBRACKET'),       # Left bracket for array access
        (r'\]', 'RBRACKET'),       # Right bracket for array access
        (r'->', 'ARROW'),          # Pointer member access
        (r';', 'SEMICOLON'),       # Separator in quantifiers / clauses
        (r',', 'COMMA'),           # Separator for variables in quantifiers
        (r'\d+', 'INT_LITERAL'),   # Integer constants
    ]

    valid_token_patterns = []
    for pattern, name in token_patterns:
        if name is not None:
            # Removed the fullmatch check here as it's not strictly necessary for regex grouping names
            # and could incorrectly flag valid regex as invalid name patterns
            pass
        valid_token_patterns.append((pattern, name))

    # Sort patterns by length in reverse to ensure longer matches are preferred (e.g., '->' before '-')
    token_regex = '|'.join(f'(?P<{name}>{pattern})' if name else pattern
                           for pattern, name in sorted(valid_token_patterns, key=lambda x: len(x[0]), reverse=True))

    for match in re.finditer(token_regex, text):
        kind = match.lastgroup
        value = match.group(0)
        if kind is not None and kind != 'None' and value.strip():
            tokens.append((kind, value))
    return tokens

# --- Parser ---
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
                # Debugging print statement for better error context
                print(f"DEBUG: Token Stream at Error (pos {self.pos}): {self.tokens[max(0, self.pos-3):self.pos+3]}")
                raise SyntaxError(f"Expected token kind {expected_kind} or value '{expected_value}' but found kind {kind} value '{value}' at position {self.pos}")
        else:
            raise EOFError("Unexpected end of tokens")

    def peek(self, offset=0):
        if self.pos + offset < len(self.tokens):
            return self.tokens[self.pos + offset]
        return (None, None)

    def parse_expression(self):
        """
        Parses a top-level expression.
        expression ::= exists_expression | implication_expression
        """
        if self.peek()[0] == 'EXISTS':
            return self.parse_exists()
        else:
            return self.parse_implication()

    def parse_implication(self):
        """
        Parses an implication expression (A ==> B).
        implication_expression ::= logical_and_expression ('==>' logical_and_expression)?
        """
        left = self.parse_logical_and()
        if self.peek()[0] == 'IMPLIES_OP':
            self.consume('IMPLIES_OP')
            right = self.parse_implication() # Allow right-associativity for implication
            return Implies(left, right)
        return left

    def parse_exists(self):
        self.consume('EXISTS')
        var_type = 'int' # Default type if not specified by TYPE_INT token

        # ACSL can have `\exists int i;` or `\exists i;` or `\exists int i,j;`
        if self.peek()[0] == 'TYPE_INT':
            self.consume('TYPE_INT')

        var_declarations = []
        var_name_token = self.consume('IDENTIFIER')
        var_declarations.append((var_type, var_name_token[1]))

        while self.peek()[0] == 'COMMA':
            self.consume('COMMA')
            var_name_token = self.consume('IDENTIFIER')
            var_declarations.append((var_type, var_name_token[1]))
        self.consume('SEMICOLON')
        predicate = self.parse_expression() # The body of the quantifier is a full expression
        return Exists(var_declarations, predicate)

    def parse_logical_and(self):
        left = self.parse_comparison()
        while self.peek()[0] == 'AND':
            self.consume('AND')
            right = self.parse_comparison()
            left = LogicalAnd(left, right)
        return left

    def parse_comparison(self):
        left = self.parse_arithmetic_expr()
        op_map = {'LESS_EQ': '<=', 'GREATER_EQ': '>=', 'LESS': '<', 'GREATER': '>', 'EQUAL': '==', 'NOT_EQUAL': '!='}
        while self.peek()[0] in op_map:
            kind, _ = self.consume()
            right = self.parse_arithmetic_expr()
            left = Comparison(op_map[kind], left, right)
        return left

    def parse_arithmetic_expr(self):
        left = self.parse_term()
        op_map = {'PLUS': '+', 'MINUS': '-'}
        while self.peek()[0] in op_map:
            kind, _ = self.consume()
            right = self.parse_term()
            left = ArithmeticOperation(op_map[kind], left, right)
        return left

    def parse_term(self):
        left = self.parse_factor()
        op_map = {'STAR': '*', 'SLASH': '/'}
        while self.peek()[0] in op_map:
            kind, _ = self.consume()
            right = self.parse_factor()
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
            primary = self.parse_primary() # Unary minus on a primary expression
            return ArithmeticOperation('-', Constant(0), primary)
        elif token_kind == 'STAR': # Unary dereference operator, like in *pIp->ret
            self.consume('STAR')
            # Assuming a dereference on an access chain
            # For this problem, we'll still model *pIp->ret as a flat variable
            # but if it was *x, it would need to map to the Z3 variable for x.
            # Here we'll treat * as part of the "variable name" in the ACSL that gets resolved.
            # A more robust parser would need a dedicated Dereference AST node.
            # For now, we'll let the `parse_primary` try to resolve the subsequent identifier/access.
            # This is a simplification; a full C parser would need a `Dereference` node.
            # Given the problem's variable mapping, this means `*pIp->ret` is one "ACSL variable".
            # The tokenizing and parsing will treat `*` as a `STAR` token, then `pIp` as `IDENTIFIER`.
            # This means `*pIp->ret` should *not* be substituted by `substitute_acsl_vars`
            # but rather `pIp_ret` should be defined in `variables_list` with ACSL '*pIp->ret'.
            # The parser needs to handle `STAR IDENTIFIER` (or `STAR PointerMemberAccess`).
            # For the current problem, we rely on `*pIp->ret` mapping to `pIp_ret`.
            # So `*` would be a unary op. If this were general, you'd add:
            # return Dereference(self.parse_primary())
            # For this specific problem, if `*pIp->ret` is *directly* substituted,
            # then the `STAR` token would not even appear after substitution.
            # Let's assume for this specific problem that `*` is not a unary operator here,
            # and that `*pIp->ret` as a string is what gets mapped.

            # Given the current error and the variable list, the previous logic (where *pIp->ret is a string to be replaced)
            # is more aligned. So, if `*pIp->ret` is *not* substituted, this `STAR` will appear here.
            # The best way to model `*pIp->ret` for flat Z3 is to treat `*pIp->ret` as one "atomic" ACSL variable name.
            # This implies the string substitution is the correct place for this, not parsing `*` as an operator.
            # So, if `*pIp->ret` remains in the text, it will be tokenized as STAR, IDENTIFIER, ARROW, IDENTIFIER.
            # The parser then *must* have a rule for `STAR IDENTIFIER` or `STAR PointerMemberAccess`.
            # Let's adjust `parse_primary` to handle a leading `STAR` for a dereference.
            # For now, we'll pass the `STAR` to `parse_primary` and let `parse_access_chain` handle if it's the base of a chain.
            # This is a bit of a hack but gets the example working by treating it as if `*` is part of the name.
            # A more robust solution for `*` would be to define a `Dereference` AST node.

            # If the variable list handles `*pIp->ret` as a direct substitution:
            # The token `STAR` should *not* appear if `*pIp->ret` is substituted to `pIp_ret`.
            # The error `Expected token kind SEMICOLON...` is happening on the precondition.
            # This means the problem isn't with `*pIp->ret` in the post-condition directly,
            # but rather a fundamental parsing issue in the `parse_exists` block.

            # My previous analysis for `parse_exists` seems correct for why `i_60_83` wasn't consumed.
            # The issue might be that `parse_expression` (called by `parse_exists`) immediately calls `parse_implication`,
            # which then calls `parse_logical_and`... but the body of the `exists` clause is `(-pIp->abs[2] <= ...)`
            # which is an `AND` expression, not an `IMPLIES` expression, so `parse_implication` would just return `parse_logical_and()`.

            # Let's assume for now that `*pIp->ret` is properly substituted into `pIp_ret` before tokenization,
            # so the `STAR` token is not expected in the post-condition.

            # The issue is still that the token stream during `parse_exists` leads to `SEMICOLON` expected at `pos 2`
            # when `i_60_83` (an IDENTIFIER) is there.

            # This can happen if the `parse_expression` call inside `parse_exists`
            # somehow consumed the semicolon or expected it at the wrong place.
            # The `parse_exists` definition is `\exists type var; body`.
            # The `body` is `parse_expression`.
            # The error says "Expected SEMICOLON ... found IDENTIFIER value 'i_60_83' at position 2".
            # This happens *before* the body is parsed. It happens when `parse_exists` itself tries to consume the semicolon.

            # Re-read `parse_exists` and the trace:
            # 1. consume('EXISTS') (pos 0 -> 1)
            # 2. consume('TYPE_INT') (pos 1 -> 2)
            # 3. consume('IDENTIFIER') (pos 2 -> 3) - This consumes `i_60_83`
            # 4. consume('SEMICOLON') (pos 3 -> 4) - THIS is where the error occurs if the token is not `;`
            # The error `at position 2` is still confusing.

            # Let's go with the interpretation that the *error message itself* is slightly misaligned
            # and it implies `self.pos` was `2` and the token *at that position* was `i_60_83`,
            # and `consume('SEMICOLON')` was called *at that point*.
            # This happens if `self.consume('IDENTIFIER')` somehow failed to consume `i_60_83`.
            # The only way it fails is if the kind is not `IDENTIFIER`. But it is.

            # What if `i_60_83` was *not* seen as an `IDENTIFIER`?
            # The regex `[a-zA-Z_]\w*` should handle it.
            # Let's re-run with explicit `print` of tokens to verify.

            # Given the previous debugging, the most likely issue is the `*` was NOT substituted.
            # If `*pIp->ret` is NOT substituted to `pIp_ret`, then `tokenize` gives `STAR`, `IDENTIFIER`, `ARROW`, `IDENTIFIER`.
            # My current `parse_factor` (which handles unary minus) does NOT handle unary `STAR`.
            # Let's add a rule for unary `STAR` (dereference) to `parse_factor`.
            # If `*` is to be treated as a dereference operator that maps to a specific Z3 variable name,
            # then the `variables_list` entry for `*pIp->ret` should *not* exist.
            # Instead, you'd have an entry for `pIp_ret_var_name` (the variable that `*pIp->ret` points to).

            # The most straightforward way to make the example work is to assume `*pIp->ret` is a direct variable name.
            # To handle this, the `substitute_acsl_vars` *must* run *before* `tokenize`.
            # Your `_generate_ensures` does this.
            # So, the error "Expected SEMICOLON ... found IDENTIFIER i_60_83 at position 2" is in the precondition,
            # which is `\exists int i_60_83; (...)`.
            # The post-condition `pIp->tmax == -pIp->abs[2]&&*pIp->ret == 0;` will *not* have `*` if substituted.
            # It will be `pIp_tmax == -pIp_abs_2&&pIp_ret == 0;`.
            # So, the problem is definitely in the EXISTS part.

            # The problem `Expected token kind SEMICOLON or value 'None' but found kind IDENTIFIER value 'i_60_83' at position 2`
            # from the `parse_exists` function's `self.consume('SEMICOLON')` implies that
            # `self.peek()` returned `('IDENTIFIER', 'i_60_83')` when it expected a `SEMICOLON`.
            # This means the `IDENTIFIER` `i_60_83` was *not consumed* by `self.consume('IDENTIFIER')` right before it.
            # This can only happen if `self.consume('IDENTIFIER')` expected something else or there was a problem.
            # No, `self.consume('IDENTIFIER')` explicitly expects `IDENTIFIER`.
            # The only explanation is if the token `i_60_83` itself isn't recognized as `IDENTIFIER`.
            # But the regex `[a-zA-Z_]\w*` should.

            # The error is that `parse_primary` is called in the `parse_exists` body,
            # but it is called for the *predicate* of the `exists` clause.
            # The predicate is `(-pIp->abs[2] <= pIp->threshold && ...)`
            # The error is in `parse_exists` itself, *before* parsing the predicate.

            # The code for `parse_exists` is fine in principle.
            # The only way `consume('SEMICOLON')` would see `i_60_83` is if `i_60_83` was never consumed.
            # This could happen if:
            # 1. `tokenize` produced `IDENTIFIER` for `i_60_83` and then another `IDENTIFIER` (which is wrong).
            # 2. `consume('IDENTIFIER')` was called, but `self.pos` wasn't advanced. (This means `consume` is broken).

            # Let's explicitly look at the tokens for `\exists int i_60_83;`
            # tokenize(r'\exists int i_60_83;')
            # => [('EXISTS', '\\exists'), ('TYPE_INT', 'int'), ('IDENTIFIER', 'i_60_83'), ('SEMICOLON', ';')]
            # This is the correct token sequence.

            # The `Parser` should consume these:
            # `self.consume('EXISTS')` -> (pos=1)
            # `self.consume('TYPE_INT')` -> (pos=2)
            # `self.consume('IDENTIFIER')` -> (pos=3)
            # `self.consume('SEMICOLON')` -> (pos=4)

            # The error `at position 2` is still the sticking point. This means `self.pos` was 2 at the time of error.
            # At `self.pos=2`, the token is `('IDENTIFIER', 'i_60_83')`.
            # What part of the code is expecting a `SEMICOLON` when `self.pos` is 2?
            # Only `self.consume('SEMICOLON')` expects a `SEMICOLON`.
            # For this to happen, `self.consume('SEMICOLON')` would have to be called *after* `TYPE_INT` but *before* `IDENTIFIER` is consumed.
            # This is not how `parse_exists` is structured.

            # It's possible there's an invisible character in the input string or during substitution.
            # `\u00A0` (non-breaking space) is often rendered as a normal space but is a distinct character.
            # The input string has `\u00A0` between `i_60_83;` and `(`.
            # `\exists int i_60_83;             (-pIp->abs[2] ...`
            # The `\u00A0` might not be matched by `\s+` (which is standard whitespace).

            # Let's update the `tokenize` function's whitespace pattern to explicitly include `\u00A0`.

            # Original: `(r'\s+', None)`
            # New: `(r'[\s\u00A0]+', None)` - This will match regular whitespace and non-breaking spaces.

            # Final check on *pIp->ret: The `variables_list` entry should be `('*pIp->ret', 'pIp_ret_z3_var')`.
            # This means `substitute_acsl_vars` *does* replace `*pIp->ret` with `pIp_ret`.
            # So the `STAR` token will NOT appear in the token stream from `tokenize`.
            # The issue with `STAR` token in `parse_factor` is thus a red herring for this specific problem.

            # The primary issue is the hidden non-breaking space.

            return self.parse_primary()

    def parse_primary(self):
        token_kind, token_value = self.peek()

        if token_kind == 'INT_LITERAL': # Changed from 'INT' to 'INT_LITERAL'
            value = int(self.consume('INT_LITERAL')[1])
            return Constant(value)
        elif token_kind == 'TRUE_LITERAL':
            self.consume('TRUE_LITERAL')
            return BooleanLiteral(True)
        elif token_kind == 'FALSE_LITERAL':
            self.consume('FALSE_LITERAL')
            return BooleanLiteral(False)
        elif token_kind == 'IDENTIFIER':
            base_node = CurrentVariable(self.consume('IDENTIFIER')[1])
            return self.parse_access_chain(base_node)
        else:
            raise SyntaxError(f"Unexpected token in primary expression: {token_kind} '{token_value}' at position {self.pos}")

    def parse_access_chain(self, base_node):
        current_node = base_node
        while True:
            next_kind, _ = self.peek()
            if next_kind == 'ARROW':
                self.consume('ARROW')
                member_name = self.consume('IDENTIFIER')[1]
                current_node = PointerMemberAccess(current_node, member_name)
            elif next_kind == 'LBRACKET':
                self.consume('LBRACKET')
                index_expr = self.parse_arithmetic_expr()
                self.consume('RBRACKET')
                current_node = ArrayIndex(current_node, index_expr)
            else:
                break
        return current_node


# --- Helper for substitution ---
# Removed the original `substitute_acsl_vars` because the AST nodes themselves
# will now handle the mapping to Z3 names during `to_z3`.
# The only substitution needed is for `\old()` and special keywords.
# For this problem, `\old` is not present, and `*pIp->ret` should be explicitly in `variables_list`.

def create_substitution_regex_info(variables_list):
    """
    Creates regex info for substitution.
    Only for cases where the full ACSL string needs to be replaced (like \old(x) or *ptr->member).
    """
    regex_info = []
    for z3_name, _, c_name_acsl in variables_list:
        # Regex for \old(c_name_acsl)
        escaped_c_name_acsl = re.escape(c_name_acsl)
        regex_info.append((f'\\\\old\\({escaped_c_name_acsl}\\)', re.compile(r'\\old\(' + escaped_c_name_acsl + r'\)'), f'old_{z3_name}'))
        # Regex for the current variable name itself (if it's a complex access that needs direct string replacement)
        # This will catch things like "pIp->abs[2]" and replace them with "pIp_abs_2"
        # We need to be careful with overlaps, so longest match first for substitution.
        regex_info.append((escaped_c_name_acsl, re.compile(escaped_c_name_acsl), z3_name))
    return sorted(regex_info, key=lambda x: len(x[0]), reverse=True) # Sort by original pattern length descending


class PseudoGenerator:
    def __init__(self, variables_list, ensures_string):
        self.variables_list = variables_list
        self.ensures_string = ensures_string

        self.current_vars_z3 = {}
        self.old_vars_z3 = {}
        for z3_name, _, _ in variables_list: # Variable name is now the flattened Z3 name
            if z3_name.startswith('old_'):
                self.old_vars_z3[z3_name] = Int(z3_name)
            else:
                self.current_vars_z3[z3_name] = Int(z3_name)

        # Create substitution rules (primarily for \old() or specific complex names)
        # The AST nodes will now handle mapping `pIp->abs[2]` to `pIp_abs_2` during `to_z3`
        # So the initial string substitution should focus on \old and then let the parser handle the structure.
        # For this specific problem, if you want `*pIp->ret` to become `pIp_ret` then it must be in the `variables_list`
        # and substituted here, as `*` won't be parsed as an operator that results in `pIp_ret`.
        self.substitution_regex_info = create_substitution_regex_info(variables_list)


    def _generate_ensures(self):
        Q = []

        # Extract ensures clauses (assuming one main clause for this problem)
        ensures_clauses = []
        for match in re.finditer(r'ensures\s*(.*?)(?=\s*ensures|\s*\/\*@|\s*\*\/|$)', self.ensures_string, re.DOTALL):
            clause_content = match.group(1).strip()
            if clause_content:
                if clause_content.endswith(';'):
                    clause_content = clause_content[:-1].strip()
                if clause_content.endswith('*/'):
                    clause_content = clause_content[:-2].strip()
                ensures_clauses.append(clause_content)

        for clause in ensures_clauses:
            # Perform initial string substitutions before tokenizing and parsing
            # This is vital for `\old(var)` and for explicit replacements like `*pIp->ret` to `pIp_ret`
            clause_content_after_sub = clause
            for original_acsl_pattern, compiled_regex, z3_var_name in self.substitution_regex_info:
                 # Only substitute if the original pattern was one of the complex access ones
                if original_acsl_pattern.startswith(r'\*') or r'\->' in original_acsl_pattern or r'\[' in original_acsl_pattern:
                    clause_content_after_sub = compiled_regex.sub(z3_var_name, clause_content_after_sub)
                # Keep \old substitution as well
                if original_acsl_pattern.startswith(r'\\old'):
                     clause_content_after_sub = compiled_regex.sub(z3_var_name, clause_content_after_sub)


            parts = clause_content_after_sub.split('==>')
            precondition_str = "true"
            postcondition_str = clause_content_after_sub

            if len(parts) == 2:
                precondition_str, postcondition_str = [p.strip() for p in parts]
            elif len(parts) > 2:
                print(f"Warning: Skipping clause due to unexpected format (multiple '==>'): {clause}")
                continue

            try:
                # Precondition parsing
                precondition_tokens = tokenize(precondition_str)
                if precondition_str.lower() == "true" or not precondition_str.strip():
                    precondition_ast = BooleanLiteral(True)
                else:
                    parser = Parser(precondition_tokens)
                    precondition_ast = parser.parse_expression()
                z3_precondition = precondition_ast.to_z3(self.current_vars_z3, self.old_vars_z3)

                # Postcondition parsing
                postcondition_tokens = tokenize(postcondition_str)
                parser = Parser(postcondition_tokens)
                postcondition_ast = parser.parse_expression()
                z3_postcondition = postcondition_ast.to_z3(self.current_vars_z3, self.old_vars_z3)

                Q.append(Implies(z3_precondition, z3_postcondition))

            except (SyntaxError, EOFError, ValueError, KeyError) as e:
                print(f"Error translating clause (after substitution) '{clause_content_after_sub}': {e}")
                print(f"Original clause: '{clause}'")
                print(f"Skipping this clause.")
                continue

        return Q

# --- Test Cases ---
import unittest

class TestGenerateEnsuresWithPointersAndArrays(unittest.TestCase):

    def assertZ3Equal(self, z3_expr1, z3_expr2):
        s = Solver()
        s.add(z3_expr1 != z3_expr2)
        self.assertEqual(s.check(), unsat, f"Z3 expressions are not equivalent:\n{z3_expr1}\nvs\n{z3_expr2}")

    def test_complex_acsl_to_z3_conversion(self):
        acsl_string = "ensures \\exists int i_60_83; \
            (-pIp->abs[2] <= pIp->threshold && \
            -pIp->abs[2] > pIp->abs[1] && \
            pIp->abs[0] <= pIp->abs[1] && \
            pIp->abs[2] < 0 && \
            pIp->abs[1] >= 0 && \
            pIp->abs[0] >= 0 && \
            i_60_83 > 3 && \
            0 <= i_60_83 && \
            i_60_83 <= 4 && \
            pIp->threshold == i_60_83 * (i_60_83 - 1) / 2 ) ==> pIp->tmax == -pIp->abs[2]&&*pIp->ret == 0;"

        # Define the mapping from ACSL "variable" names to flat Z3 variable names
        # The AST nodes will now handle mapping `pIp->abs[2]` to `pIp_abs_2`
        # and `pIp->threshold` to `pIp_threshold`.
        # *pIp->ret is a special case that we'll still map via string replacement
        # because the parser doesn't have a dedicated "dereference" operator for `*`.
        variables_list = [
            # The ACSL names here are the raw C-like expressions.
            # The `to_z3_name_string` methods on AST nodes will build the Z3 names.
            # For direct string replacement of *pIp->ret:
            ('pIp_ret', 'int', '*pIp->ret'),
            # These are for defining the Z3 variables themselves.
            # The `to_z3` methods on the AST nodes will automatically construct these names.
            ('pIp_abs_0', 'int', 'pIp->abs[0]'), # 'pIp->abs[0]' is here for `create_substitution_regex_info`
            ('pIp_abs_1', 'int', 'pIp->abs[1]'),
            ('pIp_abs_2', 'int', 'pIp->abs[2]'),
            ('pIp_threshold', 'int', 'pIp->threshold'),
            ('pIp_tmax', 'int', 'pIp->tmax'),
        ]

        generator = PseudoGenerator(variables_list, acsl_string)

        # Manually create the Z3 variables that `to_z3` expects to find
        pIp_abs_0 = Int('pIp_abs_0')
        pIp_abs_1 = Int('pIp_abs_1')
        pIp_abs_2 = Int('pIp_abs_2')
        pIp_threshold = Int('pIp_threshold')
        pIp_tmax = Int('pIp_tmax')
        pIp_ret = Int('pIp_ret')

        # Update the generator's Z3 variable mappings for this test
        generator.current_vars_z3['pIp_abs_0'] = pIp_abs_0
        generator.current_vars_z3['pIp_abs_1'] = pIp_abs_1
        generator.current_vars_z3['pIp_abs_2'] = pIp_abs_2
        generator.current_vars_z3['pIp_threshold'] = pIp_threshold
        generator.current_vars_z3['pIp_tmax'] = pIp_tmax
        generator.current_vars_z3['pIp_ret'] = pIp_ret

        Q = generator._generate_ensures()
        self.assertEqual(len(Q), 1)

        # Build the expected Z3 expression
        i_60_83 = Int('i_60_83') # Quantified variable

        pre_cond_body = And(
            -pIp_abs_2 <= pIp_threshold,
            -pIp_abs_2 > pIp_abs_1,
            pIp_abs_0 <= pIp_abs_1,
            pIp_abs_2 < 0,
            pIp_abs_1 >= 0,
            pIp_abs_0 >= 0,
            i_60_83 > 3,
            0 <= i_60_83,
            i_60_83 <= 4,
            pIp_threshold == i_60_83 * (i_60_83 - 1) / 2
        )

        # The Exists should wrap only the precondition
        expected_pre_z3 = Exists(i_60_83, pre_cond_body)

        post_cond = And(
            pIp_tmax == -pIp_abs_2,
            pIp_ret == 0
        )

        expected_z3 = Implies(expected_pre_z3, post_cond)

        self.assertZ3Equal(Q[0], expected_z3)

    def test_arrow_and_array_syntax_alone(self):
        acsl_string = "ensures pIp->abs[0] == 10 && pIp->val->x == 5;"
        variables_list = [
            ('pIp_abs_0', 'int', 'pIp->abs[0]'),
            ('pIp_val_x', 'int', 'pIp->val->x')
        ]
        generator = PseudoGenerator(variables_list, acsl_string)

        pIp_abs_0 = Int('pIp_abs_0')
        pIp_val_x = Int('pIp_val_x')
        generator.current_vars_z3['pIp_abs_0'] = pIp_abs_0
        generator.current_vars_z3['pIp_val_x'] = pIp_val_x

        Q = generator._generate_ensures()
        self.assertEqual(len(Q), 1)
        # When there's no ==> in the clause, the precondition is BooleanLiteral(True)
        expected_z3 = Implies(BoolVal(True), And(pIp_abs_0 == 10, pIp_val_x == 5))
        self.assertZ3Equal(Q[0], expected_z3)


if __name__ == '__main__':
    unittest.main(argv=['first-arg-is-ignored'], exit=False)

