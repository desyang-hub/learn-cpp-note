#pragma once

#include "alloc.h"

namespace alloc
{

class Allocator : public Alloc
{
private:
    static const size_t CHUNK_SIZE;

    struct obj {
        struct obj* next;
    };

    obj* freeStore_{nullptr};

public:
    // 获取空间
    void* allocate(size_t size) override;
    // 回收空间
    void deallocate(void* ptr, size_t size) override;
};
    
} // namespace alloc
