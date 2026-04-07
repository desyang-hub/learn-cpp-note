## pybind11 使用


### 1. 安装

```bash
pip install pybind11
```

### 2. 使用

```c++
#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.def("add", &add, "A function which adds two numbers");
}
```

```bash