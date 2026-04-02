#include <iostream>

using namespace std;

class A {
public:
    virtual ~A() = default;

};

int main() {

    cout << sizeof(A) << endl;

    return 0;
}