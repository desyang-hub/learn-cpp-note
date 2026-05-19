#include "unique_ptr_deleter_ebo.h"

int main(int argc, char const *argv[])
{
    
    auto uptr = ptr::make_unique<int>(5);
    int* t = new int(2);
    uptr.reset(t);

    delete uptr.release();

    return 0;
}
