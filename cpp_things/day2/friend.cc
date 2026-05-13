#include <iostream>

using namespace std;

class B;

class A {
    friend B;
    void say_hello() const {cout << "A:say_hello()" << endl;}
};

class B {
private:
    std::string class_name = "B";
public:
    // A 声明了B未友元类，所以B类型可以直接访问A类型的私有属性或是成员函数
    void proxy(const A& a) {a.say_hello();};

    // 友元函数不是成员函数，但是必须要在类内部声明；
    friend ostream& operator<<(ostream& os, const B& obj) {
        return os << obj.class_name;
    }
};

int main(int argc, char const *argv[])
{
    A a;
    B b;
    b.proxy(a);
    

    return 0;
}
