// #include <iostream>

// #define VIRTUAL 1

// // 演示菱形继承
// class A {
//     int a;
// public:
//     void show() const {
//         std::cout << "A::show() " << a << std::endl;
//     }

//     A(int a) : a(a) {}
// };
// #if VIRTUAL
// class B : virtual public A {
// public:
//     B(int b) : A(b) {}
// };
// class C : virtual public A {
// public:
//     C(int c) : A(c) {}
// };
// #elif
// class B : public A {};
// class C : public A {};
// #endif

// class D : public B, public C {
// public:
//     D(int d) : B(d), C(d), A(d) {}
// };

// int main(int argc, char const *argv[])
// {
//     D d(1);
//     d.show();
//     return 0;
// }


/* 虚基类调用次序(重要).cpp */
//重要!!!
#include <iostream>
using namespace std;
class A {
  int a;

public:
  A() { cout << "Constructing A" << endl; }
};
class B {
public:
  B() { cout << "Constructing B" << endl; }
};
class B1 : virtual public B, virtual public A {
public:
  B1(int i) { cout << "Constructing B1" << endl; }
};
class B2 : public A, virtual public B {
public:
  B2(int j) { cout << "Constructing B2" << endl; }
};
class D : public B1, public B2 {
public:
  D(int m, int n) : B1(m), B2(n) { cout << "Constructing D" << endl; }
  A a;
};

int main() {
  D d(1, 2);
  
  return 0;
}
