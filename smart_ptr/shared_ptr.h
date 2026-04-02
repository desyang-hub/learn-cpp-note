#pragma once

#include <assert.h>
#include <iostream>
#include <utility>

#include <iostream>

namespace ptr
{

template<class T>
class shared_ptr
{
private:
    T* ptr_ = nullptr;
    size_t* use_count_ptr_ = nullptr;

private:
    size_t use_count_plus() {
        assert(use_count_ptr);
        return ++(*use_count_ptr_);
    }

    size_t use_count_sub() {
        assert(use_count_ptr);
        return --(*use_count_ptr_);
    }

    void release() {
        if (use_count_ptr_ && use_count_sub() == 0) {
            delete ptr_;
            delete use_count_ptr_;
        }

        ptr_ = nullptr;
        use_count_ptr_ = nullptr;
    }
public:
    explicit shared_ptr(T* ptr = nullptr) : ptr_(ptr), 
        use_count_ptr_(ptr ? new size_t(1) : nullptr) {}

    ~shared_ptr() {
        release();
    }

    // 拷贝构造和拷贝赋值
    shared_ptr(const shared_ptr& ptr) : ptr_(ptr.ptr_), use_count_ptr_(ptr.use_count_ptr_) {
        use_count_plus();
    }

    shared_ptr& operator=(const shared_ptr& ptr) {
        if (&ptr != this) {
            release();
            ptr_ = ptr.ptr_;
            use_count_ptr_ = ptr.use_count_ptr_;
            use_count_plus();
        }
        return *this;
    }

    // 移动构造和移动赋值，标记未noexcept 确保容器能够使用
    shared_ptr(shared_ptr&& ptr) noexcept :
        ptr_(ptr.ptr_),
        use_count_ptr_(ptr.use_count_ptr_) 
    {
        ptr.ptr_ = nullptr;
        ptr.use_count_ptr_ = nullptr;
    }

    shared_ptr& operator=(shared_ptr&& ptr) noexcept {
        if (&ptr != this) {
            release();
            ptr_ = ptr.ptr_;
            use_count_ptr_ = ptr.use_count_ptr_;

            ptr.ptr_ = nullptr;
            ptr.use_count_ptr_ = nullptr;
        }
        return *this;
    }

public:
    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* get() const {
        return ptr_;
    }

    size_t use_count() const {
        return *use_count_ptr_;
    }

};

template<class T, typename ...Args> 
shared_ptr<T> make_shared(Args&& ...args) {
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

    
} // namespace ptr
