#include <iostream>

using namespace std;


int main() {

    int counter{0};

    // 虽然看起来有点反直觉（“既然是我的副本，为什么我不能改？”），但这完全是 C++ 为了类型安全和函数式纯洁性所做的妥协。
    auto incrementer = [counter]() mutable {
        counter++; 
    };
    incrementer();

    return 0;
}