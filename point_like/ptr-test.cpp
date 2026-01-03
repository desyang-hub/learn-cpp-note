#include "ptr.h"

using namespace std;

class A {
public:
    A() {
        cout << "Call A ctor function" << endl;
    }

    ~A() {
        cout << "Call ~A() dtor function" << endl;
    }

    void show() const {
        cout << "Show A class attibute" << endl;
    }
};

int main() {

    auto ptr = Ptr<A>(new A());

    ptr->show();

    return 0;
}