#include <iostream>

#define VIRTUAL 1

// 演示菱形继承
class A {
public:
    void show() const {
        std::cout << "A::show()" << std::endl;
    }
};
#if VIRTUAL
class B : virtual public A {};
class C : virtual public A {};
#elif
class B : public A {};
class C : public A {};
#endif

class D : public B, public C {};

int main(int argc, char const *argv[])
{
    D d;
    d.show();
    return 0;
}
