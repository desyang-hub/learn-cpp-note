#pragma once

namespace ptr
{

template<class T>
class unique_ptr
{
private:
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;
    
    pointer ptr_;
public:
    explicit unique_ptr(pointer ptr = nullptr);
    ~unique_ptr() {
        if (ptr_) delete ptr_;
        ptr_ = nullptr;
    }

    // 禁用拷贝
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // 移动构造
    template<class U>
    unique_ptr(unique_ptr<U>&& other) noexcept  {
        ptr_ = other.release();
    }

    template<class U>
    unique_ptr& operator=(unique_ptr<U>&& other) noexcept {
        // swap(*this, std::move(other));
        ptr_ = other.release();
        return *this;
    }

    // copy and swap
    unique_ptr& operator=(unique_ptr ptr) noexcept {
        swap(*this, ptr); // 这里将自己的指针交还给局部变量ptr.ptr_，作用域结束，自动析构
        return *this;
    }

public:
    pointer get() const {return ptr_;}

    reference operator*() const {return *ptr_;}

    pointer operator->() const {return ptr_;}

    pointer release() {
        pointer p = ptr_;
        ptr_ = nullptr;
        return p;
    }

    template<class U>
    void reset(U* ptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    operator bool() const {return ptr_;}

    void swap(unique_ptr& ptr) noexcept {
        using std::swap;
        ::swap(ptr_, ptr.ptr_);
    }
};

template<class T>
inline unique_ptr<T>::unique_ptr(pointer ptr) : ptr_(ptr)
{
}

template<class T>
inline unique_ptr<T>::~unique_ptr()
{
    if (ptr_) delete ptr_;
    ptr_ = nullptr;
}

template<class T>
void swap(unique_ptr<T>& lhs, unique_ptr<T>& rhs) {
    lhs.swap(rhs);
}

    
} // namespace ptr
