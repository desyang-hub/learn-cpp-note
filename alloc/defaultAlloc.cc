#include "alloc.h"
#include "allocator.h"

using namespace alloc;

Alloc* Alloc::GetDefaultAlloc() {
    return new Allocator();
}