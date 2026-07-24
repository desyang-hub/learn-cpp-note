#include <iostream>

using namespace std;

class A {
public:
    virtual ~A() = default;

    virtual void say() {
        std::cout << "A" << std::endl;
    }
};

class B : public A {
public:
    void say() override {
        std::cout << "B" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // static_cast
    size_t a = 10;
    int b = static_cast<int>(a);

    // dynamic_cast 用于多台父子类之间的转换
    B ib;
    A ia;
    A& ic = ib;
    ic.say();

    B& id = dynamic_cast<B&>(ic);
    id.say();

    // const cast 去掉const/volatile属性，(慎用，除非你确定元对象本来就不是const)
    int c = 5;
    auto modify = [](const int& c) {
        int& d = const_cast<int&>(c);
        d = 6;
    };
    modify(c);
    std::cout << c << std::endl;

    int d = 68;
    char& e = reinterpret_cast<char&>(d);
    std::cout << e << std::endl;

    return 0;
}
