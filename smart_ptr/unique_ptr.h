#pragma once

#include "nonecopyable.h"

#include <iostream>
#include <utility>
#include <assert.h>

namespace ptr
{

template<class T>
class unique_ptr : public nonecopyable
{
public:
    unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}
    ~unique_ptr() {delete ptr_; ptr_ = nullptr;}

    // 移动构造
    unique_ptr(unique_ptr&& ptr) noexcept {
        swap(ptr);
    }
    unique_ptr& operator=(unique_ptr&& ptr) noexcept {
        if (&ptr != this) {
            unique_ptr(std::move(ptr)).swap(*this);
        }
        return *this;
    }

private:
    void swap(unique_ptr& ptr) {
        std::swap(ptr_, ptr.ptr_);
    }

public:
    T& operator*() const {
        assert(ptr_ != nullptr);
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* get() const {
        return ptr_;
    }

    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

private:
    T* ptr_ = nullptr;
};

template<class T, typename ...Args>
unique_ptr<T> make_unique(Args&& ...args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}
    
} // namespace ptr
