#include "allocator.h"

#include <iostream>

using namespace alloc;


const size_t Allocator::CHUNK_SIZE = 20;


// 获取空间
void* Allocator::allocate(size_t size) {
    obj* p = nullptr;
    
    std::cout << "allocate: " << size << std::endl;
    
    if (freeStore_ == nullptr) { // 没有可用的空间了，分配空间
        freeStore_ = (obj*)malloc(size * CHUNK_SIZE);

        p = freeStore_;

        for (int i = 1; i < CHUNK_SIZE; ++i) {
            p->next = (obj*)((char*)p + size);
            p = p->next;
        }
        p->next = nullptr;
    }

    // 分配空间
    p = freeStore_;
    freeStore_ = freeStore_->next;

    return p;
}

// 回收空间
void Allocator::deallocate(void* ptr, size_t size) {
    // 将释放的空间重新回收到链表中
    static_cast<obj*>(ptr)->next = freeStore_;
    freeStore_ = static_cast<obj*>(ptr)->next;
}