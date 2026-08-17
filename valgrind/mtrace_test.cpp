// mtrace_test.c
#include <stdlib.h>
#include <mcheck.h>  // ← 关键头文件

int main() {
    mtrace();  // ← 开启追踪

    char *a = (char*)malloc(100);
    char *b = (char*)malloc(200);
    free(a);
    // b 未释放

    muntrace();  // ← 关闭追踪（可选，程序退出时自动停止）
    return 0;
}