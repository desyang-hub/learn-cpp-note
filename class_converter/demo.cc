#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};
    


int main() {
    // ======== static_cast ========
    // 1. 用途最广泛，用于任何编译器隐式允许的转换，以及它们的反向转换。
    // 2. 可用于基础数据类型之间的转换（如int转double, enum转int）。
    // 3. 可用于具有转换构造函数的类类型转换。
    // 4. 可用于void指针与具体类型指针之间的转换（如void* -> int*）。
    // 5. 可用于类层次结构中向上转换（派生类指针/引用 -> 基类指针/引用，这是安全的），
    // 6. 也可用于向下转换（基类 -> 派生类），但不进行运行时检查，不安全。

    int i = 42;
    double d = static_cast<double>(i); // 基础类型转换

    void* pv = &i;
    int* pi = static_cast<int*>(pv); // 转换回原来的类型

    Base* base_ptr = new Derived();
    // 向上转换 static_cast 安全 Derived* -> Base*
    Base* base_ptr2 = static_cast<Base*>(new Derived());


    // 2. 安全动态转换示例 dynamic_cast 安全的下行转换
    Derived* derived = dynamic_cast<Derived*>(base_ptr);
    if (derived) { // 转换成功
        std::cout << "DownCast success." << std::endl;
    }

    Base* base_ptr3 = new Base();
    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr3);
    if (derived_ptr == nullptr) { // 转换失败
        std::cout << "DownCast failed." << std::endl;
    }



    // 4. reinterceptor_cast 最低层次，最不安全，直接将一块内存的比特位解释称另外一种类型
    long long addr = reinterpret_cast<long long>(pi);
    // 将一个地址转换为一个long long 类型数字
    std::cout << "addr: " << addr << std::endl;


    // 将一个int指针强制解释成一个double指针(是危险的)
    double* pd = reinterpret_cast<double*>(pi);
    std::cout << "*pd: " << *pd << std::endl; // 将输出无意义的垃圾值

    delete base_ptr;
    delete base_ptr2;
    delete base_ptr3;

    return 0;
}