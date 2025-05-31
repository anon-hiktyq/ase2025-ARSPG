from dataclasses import dataclass, field
from typing import Union, List, Optional, Tuple


@dataclass
class Parameter:
    def __init__(self, name = None, type = None, is_ptr = False, ptr_depth = 0, is_struct = False,array_length = -1):
        self.name = name
        self.type = type
        self.is_ptr = is_ptr
        self.ptr_depth = ptr_depth
        self.is_struct = is_struct
        self.array_length = array_length
    name: str
    type: Union[str, 'StructInfo']  # 参数类型可以是字符串或StructInfo
    is_ptr: bool
    ptr_depth:int
    is_struct: bool
    array_length: int

@dataclass
class StructInfo:
    def __init__(self, type, parameters_list):
        self.type = type
        self.parameter_list = parameters_list
    type: str
    parameter_list: List[Parameter]  # 结构体的参数列表


@dataclass
class TypeInfo:
    def __init__(self, name, file_path, content_range, code, included_types=None):
        self.name = name
        self.file_path = file_path
        self.content_range = content_range
        self.code = code
        self.alias_set = set()
        self.included_types = included_types if included_types else set()
    name: str
    code: str
    included_types: set[str]  # 该类型依赖的其他类型



@dataclass
class FunctionInfo:
    def __init__(self, file_path = None, name = None, code = None, callee_set = None, func_type = None):
        self.file_path = file_path
        self.name = name
        self.code = code
        self.callee_set = callee_set if callee_set else set()
        self.func_type = func_type
        self.parameter_list = []
        self.annotation = str()
        self.specification = str()
        self.include = str()
        
    file_path: str
    name: str
    code: str
    callee_set: set[str]
    func_type: str
    parameter_list: Optional[List[Parameter]]
    annotation: str
    specification: str
    include: str


@dataclass
class DefInfo:
    typedef_list: List[str]
    define_list: dict[str:str]
