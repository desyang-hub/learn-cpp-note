#include <iostream>
#include <memory>
#include <string.h>

// 这里展示函数全特化样例程序

namespace func {
template<class T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

};

int main(int argc, char const *argv[])
{
    const char* a = "aaa";
    const char* b = "b";

    if (strcmp(a, b) > 0) {
        std::cout << a << std::endl;
    } else {
        std::cout << b << std::endl;
    }

    std::string res = func::max(std::string(a), std::string(b));

    std::cout << res << std::endl;
    
    return 0;
}
