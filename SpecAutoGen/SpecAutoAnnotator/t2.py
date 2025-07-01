
import tree_sitter_c as tspython
from tree_sitter import Language, Parser

def record_type(source_code, parser):
    """
    在 C 源代码中查找 typedef、struct、union 和 enum 的定义并返回一个字典。

    Args:
        source_code (bytes): C 源代码的字节串。
        parser (Parser): 已经设置好 C 语言的 tree-sitter 解析器。

    Returns:
        dict: 一个字典，键是类型名称，值是类型定义的源代码字符串。
    """
    tree = parser.parse(source_code)
    type_dict = {}

    def traverse(node):
        # 处理 typedef 定义
        if node.type == "type_definition":
            typedef_name = None
            typedef_source = node.text

            for child in node.children:
                if child.type == "type_identifier":
                    typedef_name = child.text.decode('utf-8')
                    break

            if typedef_name:
                type_dict[typedef_name] = typedef_source.decode('utf-8')
            return


        # 处理 struct 定义
        elif node.type == "struct_specifier":
            
            struct_name_node = None
            struct_source = node.text

            for child in node.children:
                if child.type == "type_identifier":
                    struct_name_node = child
                    break

            if struct_name_node:
                struct_name = struct_name_node.text.decode('utf-8')
                type_dict[struct_name] = struct_source.decode('utf-8') + ';'
            return


        # 处理 union 定义
        elif node.type == "union_specifier":
            union_name_node = None
            union_source = node.text

            for child in node.children:
                if child.type == "type_identifier":
                    union_name_node = child
                    break

            if union_name_node:
                union_name = union_name_node.text.decode('utf-8')
                type_dict[union_name] = union_source.decode('utf-8') + ';'
            return

        # 处理 enum 定义
        elif node.type == "enum_specifier":
            enum_name_node = None
            enum_source = node.text

            for child in node.children:
                if child.type == "type_identifier":
                    enum_name_node = child
                    break

            if enum_name_node:
                enum_name = enum_name_node.text.decode('utf-8')
                type_dict[enum_name] = enum_source.decode('utf-8') + ';'
            return

        # 递归遍历子节点
        for child in node.children:
            traverse(child)

    traverse(tree.root_node)
    return type_dict

# 示例用法 (需要先配置 parser)
if __name__ == "__main__":
  
    C_LANGUAGE = Language(tspython.language())
    parser = Parser(C_LANGUAGE)

    source_code = b"""
    typedef struct MyPoint {
        int x;
        int y;
    } MyPointAlias;

    struct AnotherPoint {
        float a;
        float b;
    };

    union Data {
        int i;
        float f;
    };

    enum Status {
        OK,
        ERROR
    };

    int main() {
        struct AnotherPoint p;
        union Data d;
        enum Status s = OK;
        MyPointAlias mp;
        return 0;
    }
    """

    type_definitions = record_type(source_code, parser)
    for name, definition in type_definitions.items():
        print(f"Type Name: {name}")
        print(f"Definition:\n{definition}\n---")