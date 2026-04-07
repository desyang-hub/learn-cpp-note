def add(i : int, j : int) -> int:
    ...

def inadd() -> None:
    ...


# 2. 运行时导入真正的 C++ 模块
try:
    from . import example as _cpp_impl
    
    # 将 C++ 的实际函数赋值给 Python 的存根函数
    # 这样既保留了类型提示，又替换了实现
    add = _cpp_impl.add
    
    # 如果你也想导出 inadd，记得在这里赋值
    inadd = _cpp_impl.inadd 
    
    # 3. 控制导出范围
    __all__ = ['add', 'inadd']  # 只有 add 会被 from example import * 导出
    
except ImportError as e:
    # 开发阶段友好的错误提示：如果 .so 还没编译，导入时会报错
    raise ImportError(
        "C++ 扩展模块 'example' 未找到。请先编译项目。\n"
        f"原始错误: {e}"
    )