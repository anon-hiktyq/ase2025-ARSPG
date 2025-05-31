import re

class ACSLSyntaxParser:
    """
    A simple parser for a subset of ACSL syntax.

    Limitations:
    - This parser is based on regular expressions and string manipulation,
      and thus has limitations in handling complex nested structures and
      the full generality of ACSL.
    - It focuses on identifying the main syntactic categories defined
      in the provided grammar.
    - It does not build a full abstract syntax tree (AST) but rather
      identifies and extracts key components.
    - Error handling is basic.
    """

    def __init__(self):
        pass

    def parse_predicate_declaration(self, line):
        """Parses predicate declarations like '/*@ predicate f(term t1, term t2, ...); */'."""
        match = re.match(r'\/\*\@ predicate\s+(\w+)\s*\(([^)]*)\)\s*;\s*\*\/\s*$', line)
        if match:
            predicate_name = match.group(1)
            arguments_str = match.group(2).strip()
            arguments = [arg.strip() for arg in arguments_str.split(',')] if arguments_str else []
            return {"type": "predicate_declaration", "name": predicate_name, "arguments": arguments}
        return None

    def parse_logic_term_declaration(self, block):
        """Parses the logic term declaration block."""
        if "/*@ logic term ::=" in block and "; */" in block:
            start_index = block.find("/*@ logic term ::=") + len("/*@ logic term ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                productions_str = block[start_index:end_index].strip()
                productions = [p.strip() for p in productions_str.split('|')]
                return {"type": "logic_term_declaration", "productions": productions}
        return None

    def parse_logic_op_declaration(self, block):
        """Parses the logic op declaration block."""
        if "/*@ logic op ::=" in block and "; */" in block:
            start_index = block.find("/*@ logic op ::=") + len("/*@ logic op ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                operators_str = block[start_index:end_index].strip()
                operators = [op.strip() for op in operators_str.split('|')]
                return {"type": "logic_op_declaration", "operators": operators}
        return None

    def parse_logic_unop_declaration(self, block):
        """Parses the logic unop declaration block."""
        if "/*@ logic unop ::=" in block and "; */" in block:
            start_index = block.find("/*@ logic unop ::=") + len("/*@ logic unop ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                unoperators_str = block[start_index:end_index].strip()
                unoperators = [op.strip() for op in unoperators_str.split('|')]
                return {"type": "logic_unop_declaration", "unoperators": unoperators}
        return None

    def parse_logic_prop_formula_declaration(self, block):
        """Parses the logic prop_formula declaration block."""
        if "/*@ logic prop_formula ::=" in block and "; */" in block:
            start_index = block.find("/*@ logic prop_formula ::=") + len("/*@ logic prop_formula ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                productions_str = block[start_index:end_index].strip()
                productions = [p.strip() for p in productions_str.split('|')]
                return {"type": "logic_prop_formula_declaration", "productions": productions}
        return None

    def parse_logic_sep_formula_declaration(self, block):
        """Parses the logic sep_formula declaration block."""
        if "/*@ logic sep_formula ::=" in block and "; */" in block:
            start_index = block.find("/*@ logic sep_formula ::=") + len("/*@ logic sep_formula ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                productions_str = block[start_index:end_index].strip()
                productions = [p.strip() for p in productions_str.split('|')]
                return {"type": "logic_sep_formula_declaration", "productions": productions}
        return None

    def parse_predicate_single_assertion_formula_declaration(self, block):
        """Parses the predicate single_assertion_formula declaration block."""
        if "/*@ predicate single_assertion_formula ::=" in block and "; */" in block:
            start_index = block.find("/*@ predicate single_assertion_formula ::=") + len("/*@ predicate single_assertion_formula ::=")
            end_index = block.find("; */", start_index)
            if start_index != -1 and end_index != -1:
                productions_str = block[start_index:end_index].strip()
                productions = [p.strip() for p in productions_str.split('|')]
                return {"type": "single_assertion_formula_declaration", "productions": productions}
        return None

    def parse_assert_annotation(self, line):
        """Parses assert annotations like '/*@ assert single_assertion_formula ; */'."""
        match = re.match(r'\/\*\@ assert\s+(.+?)\s*;\s*\*\/\s*$', line)
        if match:
            assertion = match.group(1).strip()
            return {"type": "assert_annotation", "assertion": assertion}
        return None

    def parse_loop_invariant_annotation(self, line):
        """Parses loop invariant annotations like '/*@ loop invariant single_assertion_formula ; */'."""
        match = re.match(r'\/\*\@ loop invariant\s+(.+?)\s*;\s*\*\/\s*$', line)
        if match:
            invariant = match.group(1).strip()
            return {"type": "loop_invariant_annotation", "invariant": invariant}
        return None

    def parse_acsl_text(self, acsl_text):
        """Parses a block of ACSL text and identifies its components."""
        lines = acsl_text.strip().split('\n')
        parsed_elements = []
        i = 0
        while i < len(lines):
            line = lines[i].strip()
            if line.startswith("/*@ predicate"):
                parsed = self.parse_predicate_declaration(line)
                if parsed:
                    parsed_elements.append(parsed)
            elif line.startswith("/*@ logic term ::="):
                # Find the entire logic term block
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_logic_term_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated logic term declaration starting at line {i+1}")
            elif line.startswith("/*@ logic op ::="):
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_logic_op_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated logic op declaration starting at line {i+1}")
            elif line.startswith("/*@ logic unop ::="):
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_logic_unop_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated logic unop declaration starting at line {i+1}")
            elif line.startswith("/*@ logic prop_formula ::="):
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_logic_prop_formula_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated logic prop_formula declaration starting at line {i+1}")
            elif line.startswith("/*@ logic sep_formula ::="):
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_logic_sep_formula_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated logic sep_formula declaration starting at line {i+1}")
            elif line.startswith("/*@ predicate single_assertion_formula ::="):
                j = i
                block = ""
                while j < len(lines) and "; */" not in lines[j]:
                    block += lines[j] + "\n"
                    j += 1
                if j < len(lines):
                    block += lines[j]
                    parsed = self.parse_predicate_single_assertion_formula_declaration(block)
                    if parsed:
                        parsed_elements.append(parsed)
                    i = j
                else:
                    print(f"Error: Unterminated single_assertion_formula declaration starting at line {i+1}")
            elif line.startswith("/*@ assert"):
                parsed = self.parse_assert_annotation(line)
                if parsed:
                    parsed_elements.append(parsed)
            elif line.startswith("/*@ loop invariant"):
                parsed = self.parse_loop_invariant_annotation(line)
                if parsed:
                    parsed_elements.append(parsed)
            i += 1
        return parsed_elements

# Example usage:
acsl_code = r"""
/*@
  loop invariant (\at(a, Pre)<10) ==> (((a == \at(a, Pre))) || (a >= \at(a, Pre) && a <= 10));
  loop invariant (!(\at(a, Pre)<10)) ==> ((a == \at(a, Pre)));
*/
"""

parser = ACSLSyntaxParser()
syntax_tree = parser.parse_acsl_text(acsl_code)

for element in syntax_tree:
    print(element)