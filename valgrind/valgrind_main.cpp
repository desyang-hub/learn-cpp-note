// test.c
#include <stdlib.h>
#include <string.h>

int main() {
    // 1. 未释放的堆内存（泄漏）
    char *leak = (char*)malloc(64);
    strcpy(leak, "hello");

    // 2. 越界写
    char *buf = (char*)malloc(8);
    buf[8] = 'x';  // off-by-one

    // 3. 使用未初始化内存
    int *p = (int*)malloc(sizeof(int));
    if (*p == 0) { }  // 读取未初始化值

    free(buf);
    // leak 和 p 未 free
    return 0;
}