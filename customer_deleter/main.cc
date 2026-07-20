#include "shared_deleter.h"
#include <memory>
#include <iostream>

struct my_deleter {
    void operator()(int* p) {
        if (p) {
            std::cout << "val: " << *p << std::endl;
            delete p;
        }
        std::cout << "delete resource." << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    
    int* v = new int(1);
    auto vPtr = std::unique_ptr<int, my_deleter>(v);

    int* v1 = new int(2);
    auto sp = std::shared_ptr<int>(v1, my_deleter());

    int* v2 = new int(3);
    auto cus_deleter = [](int* p){
        std::cout << "*p: " << *p << std::endl;
        if (p) {
            delete p;
            std::cout << "call delete" << std::endl;
        }
    };
    auto v2Guard = std::unique_ptr<int, decltype(cus_deleter)>(v2, cus_deleter);

    int* arr = new int[10];
    auto arr_deleter = [](int p[]) {
        std::cout << p << std::endl;
        if (p) {
            delete[] p;
            std::cout << "call delete" << std::endl;
        }
    };
    auto arrGuard = std::shared_ptr<int[]>(arr, arr_deleter);

    return 0;
}
