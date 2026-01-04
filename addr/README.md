> 为什么像 "abcd" 这样的“临时”字符串字面量可以取地址，而像 std::pair{1,2} 这样的临时对象不能直接取地址（比如 &std::pair{1,2}）？
- 只有左值(lvalue)能够取地址,临时变量属于右值(rvalue)
- 在 C++ 中，字符串字面量（如 "abcd"）不是临时对象，而是具有 静态存储期（static storage duration） 的 左值（lvalue）。