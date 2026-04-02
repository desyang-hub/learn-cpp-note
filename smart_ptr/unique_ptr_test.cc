#include "unique_ptr.h"

#include <iostream>

using namespace std;
using namespace ptr;

class Integer {
    public:
        explicit Integer(int value = 0) : val_(value) {
            cout << __FUNCTION__ << " val: " << val_ << endl;
        }
    
        ~Integer() {
            cout << __FUNCTION__ << " val: " << val_ << endl;
        }
    private:
        int val_;
};

int main() {

    auto ptr = make_unique<Integer>(19);

    unique_ptr<Integer> int1 = make_unique<Integer>(2);
    ptr = std::move(int1);

    ptr = make_unique<Integer>(18);

    auto ptr1 = ptr.release();

    delete ptr1;

    return 0;
}

/*
Integer val: 19
unique_ptr construct, addr=0x60b1fc4feeb0
~Integer val: 19
unique_ptr destroy, addr=0
*/