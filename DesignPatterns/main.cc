#define LOG_LEVEL 1 
// 为什么宏一般出现头文件前面，因为，头文件中包含了根据宏来判断内部的替换逻辑，所以宏必须出现在头文件之前
#include <iostream>
#include "utils.h"
#include "designpatterns.h"
using namespace std;




int main(int argc, char const *argv[])
{

    singletone_demo();
    observer_demo();
    strategy_demo();
    decorator_demo();
    

    return 0;
}
