#include "shared_ptr.h"

#include <iostream>

using namespace ptr;
using std::cout;
using std::endl;

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

    auto sp1 = make_shared<Integer>(10);
    shared_ptr<Integer> sp2 = sp1;

    shared_ptr<Integer> sp3 = std::move(sp1);

    cout << sp2.use_count() << endl;

    return 0;
}