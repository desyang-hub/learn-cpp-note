#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "Call construct" << endl;
    }

    ~A() {
        cout << "Call Destruct" << endl;
    }
};


class B : public A {
public:
    B() {
        cout << "Call B construct" << endl;
    }

    ~B() {
        cout << "Call B Destruct" << endl;
    }
};

int main() {

    B();
    cout << "hhhh" << endl;
    return 0;
}