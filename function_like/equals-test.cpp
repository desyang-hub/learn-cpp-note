#include <iostream>
#include "equals.h"

using namespace std;

class A {};

class B : public A{};



int main() {
    B b;
    A* a = &b;

    cout << "a == b: " << equals<A, B>()(*a, b) << endl;

    return 0;
}