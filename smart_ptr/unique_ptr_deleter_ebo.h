#pragma once

#include <iostream>

namespace ptr
{

template<class T>
struct default_deleter {
    void operator()(T* ptr) const {
        std::cout << "default_deleter process" << std::endl;
        delete ptr;
    }
};


template<class T, class Deleter = default_deleter<T>>
class unique_ptr : private Deleter
{
private:
    using pointer  = T*;
    using reference = T&;

    pointer ptr_;
public:
    unique_ptr(pointer p = nullptr) : ptr_(p) {}
    ~unique_ptr() {
        if (ptr_)
            get_deleter()(ptr_);
    }

    // 禁用拷贝
    unique_ptr(const unique_ptr& p) = delete;
    unique_ptr& operator=(const unique_ptr& p) = delete;

    // 移动
    unique_ptr(unique_ptr&& p) noexcept : Deleter(std::move(p)), ptr_(p.release()) {
    }

    unique_ptr& operator=(unique_ptr&& p) noexcept {
        if (this != &p) {
            get_deleter() = std::move(p.get_deleter());
            ptr_ = p.release();
        }
        
        return *this;
    }

    template<class U, class D>
    friend class unique_ptr;

    // copy and swap
    template<class U>
    unique_ptr(unique_ptr<U> p) noexcept : Deleter(std::move(p.get_deleter())), ptr_(p.release()) {}

    template<class U>
    unique_ptr& operator=(unique_ptr<U> p) noexcept {
        if (ptr_ != p.ptr_) {
            get_deleter()(ptr_);
            get_deleter() = std::move(p.get_deleter());
            ptr_ = p.ptr_;
        }
        return *this;
    }

public:
    operator bool() const {
        return ptr_;
    }

    pointer release() {
        pointer p = ptr_;
        ptr_ = nullptr;
        return p;
    }

    template<class U>
    void reset(U* ptr = nullptr) {
        static_assert(std::is_convertible<U*, pointer>::value && "U* must convert T*");
        if (ptr_)
            get_deleter()(ptr_);
        ptr_ = ptr;
    }

    pointer get() const {return ptr_;}

    reference operator*() const {return *ptr_;}

    pointer operator->() const {return ptr_;}

    Deleter& get_deleter() noexcept {
        return *this;
    }
    
    const Deleter& get_deleter() const noexcept {
        return *this;
    }
};


template<class T, typename ...Args>
unique_ptr<T> make_unique(Args&& ...args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

    
} // namespace ptr
