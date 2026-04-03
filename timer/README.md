## 计时器设计

1. 能够通过宏来启用函数耗时打印
2. RAII管理生命周期

### 使用说明

```cpp
#include "Timer.h"

#include <iostream>
#include <cstring>

void test() {

    TIMER_START_TAG(timer01);
    for (int i = 0; i < 1e8; ++i) {
        i++;
    }
    TIMER_FINISH_TAG(timer01);
    // TIMER_FINISH();

    TIMER_START();
    for (int i = 0; i < 1e8; ++i) {
        i++;
    }
}

int main() {
    test();
    return 0;
}

```