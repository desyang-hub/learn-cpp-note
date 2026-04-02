#pragma once

#include <iostream>

/**
 * @usage: 只需要将DECLARE_POOL_ALLOC(); 添加到自定义类的最后一行，
 * 并在对于类实现.cc/.cpp文件中IMPLEMENT_POOL_ALLOC(CLASS_NAME);即可
 * 
 * @warning: 请确保自定义类的所占用字节数大于8(64位， 4/32位)
 */
#define DECLARE_POOL_ALLOC() \
    protected: \
    static std::unique_ptr<alloc::Alloc> alloc_; \
    public: \
    static void* operator new(size_t size) { \
        return alloc_->allocate(size); \
    } \
    static void operator delete(void* ptr, size_t size) { \
        return alloc_->deallocate(ptr, size); \
    }

#define IMPLEMENT_POOL_ALLOC(CLASS_NAME) \
std::unique_ptr<alloc::Alloc> CLASS_NAME::alloc_ = std::unique_ptr<alloc::Alloc>(alloc::Alloc::GetDefaultAlloc());




namespace alloc
{

class Alloc
{
public:
    // 获取空间
    virtual void* allocate(size_t size) = 0;
    // 回收空间
    virtual void deallocate(void* ptr, size_t size) = 0;

    static Alloc* GetDefaultAlloc();
};
    
} // namespace alloc
