#include "alloc.h"

#include <iostream>
#include <memory>

using namespace std;
// using namespace alloc;

class Integer
{
// protected:
//     static std::unique_ptr<Alloc> alloc_;
// public:
//     static void* operator new(size_t size) {
//         return alloc_->allocate(size);
//     }

//     static void operator delete(void* ptr, size_t size) {
//         return alloc_->deallocate(ptr, size);
//     }

private:
public:
    Integer();
    virtual ~Integer();

DECLARE_POOL_ALLOC();
};

IMPLEMENT_POOL_ALLOC(Integer);

// std::unique_ptr<Alloc> Integer::alloc_ = std::unique_ptr<Alloc>(Alloc::GetDefaultAlloc());

Integer::Integer(/* args */)
{
    cout << "construct" << endl;
}

Integer::~Integer()
{
    cout << "destruct" << endl;
}


int main() {

    Integer* a = new Integer();
    Integer* b = new Integer();

    delete a;
    delete b;

    return 0;
}