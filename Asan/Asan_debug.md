你提到的 CMake 指令：

```cmake
target_compile_options(server_d12 PRIVATE -fsanitize=address -fno-omit-frame-pointer -O1)
target_link_options(server_d12 PRIVATE -fsanitize=address)
```

是用来为 CMake 目标 `server_d12` 启用 **AddressSanitizer（ASan）** 的。如果你不使用 CMake，而是直接使用 `g++` 命令行来编译和链接程序，那么你需要手动将这些选项添加到编译和链接命令中。

---

### ✅ 如何在 `g++` 构建命令中启用 AddressSanitizer？

#### 1. **编译阶段（Compilation）**
你需要添加以下编译选项：

```bash
g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g -c your_source.cpp -o your_source.o
```

说明：
- `-fsanitize=address`：启用 AddressSanitizer。
- `-fno-omit-frame-pointer`：保留帧指针，有助于生成更清晰的堆栈跟踪。
- `-O1`：推荐使用 `-O1` 而不是 `-O0` 或 `-O2+`，因为 ASan 在 `-O1` 下表现最稳定。
- `-g`：包含调试信息（强烈建议加上，否则报错时看不到源码行号）。

#### 2. **链接阶段（Linking）**
链接时同样要加上 `-fsanitize=address`：

```bash
g++ -fsitize=address your_source.o -o your_program
```

或者一步完成编译+链接：

```bash
g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g your_source.cpp -o your_program
```

> ⚠️ 注意：**编译和链接阶段都必须加上 `-fsanitize=address`**，否则运行时会出错或无法检测内存问题。

---

### 🧪 运行程序

直接运行即可：

```bash
./your_program
```

如果程序中有内存错误（如堆栈溢出、use-after-free、越界访问等），ASan 会输出详细的错误报告，包括调用栈、内存地址、错误类型等。

---

### 🔒 注意事项

- AddressSanitizer 会显著增加内存使用（通常 2~3 倍）和降低运行速度（约 2~3 倍），仅用于调试，**不要用于生产环境**。
- 如果你的程序使用了多线程、动态库、或自定义内存分配器，可能需要额外配置。
- GCC 版本需 ≥ 4.8（推荐 ≥ 7.0 以获得完整功能）。

---

如有更多构建细节（比如多个源文件、使用 Makefile 等），也可以继续提问！