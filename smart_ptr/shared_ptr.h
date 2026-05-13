#pragma once

#include <atomic>
#include <assert.h>
#include <stddef.h>
#include <iostream>

namespace ptr
{
    
class shared_count {
private:
    std::atomic<long> count_;

public:
    shared_count() : count_(1) {}

    long add_count() {
        return ++count_;
    }

    long reduce_count() {
        return --count_;
    }

    long get_count() const {
        return count_.load();
    }
};

template<class T>
class shared_ptr final
{
private:
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;


    shared_count* count_;
    pointer ptr_;

    void destroy() {
        

        if (count_ == nullptr || count_->reduce_count() == 0) {
            delete ptr_;
            ptr_ = nullptr;
            count_ = nullptr;
        }
    }
public:
    shared_ptr(pointer ptr=nullptr) : ptr_(ptr), count_(new shared_count()) {

    }
    ~shared_ptr() {
        destroy();
    }

    // 拷贝构造
    shared_ptr(const shared_ptr& p) : ptr_(p.ptr_), count_(p.count_) {
        count_->add_count(); // 引用计数++
    }

    template<class U>
    friend class shared_ptr;

    template<class U>
    shared_ptr(const shared_ptr<U>& p) : ptr_(p.ptr_), count_(p.count_) {
        std::cout << "copy" << std::endl;
        count_->add_count(); // 引用计数++
    }

    shared_ptr& operator=(const shared_ptr& p) {
        destroy(); // 销毁原有的资源
        ptr_ = p.ptr_;
        count_ = p.count_;
        count_->add_count();
        return *this;
    }

    // 移动操作
    shared_ptr(shared_ptr&& p) noexcept : ptr_(p.ptr_), count_(p.count_) {
        p.ptr_ = nullptr;
        p.count_ = nullptr;
    }

    template<class U>
    shared_ptr(shared_ptr<U>&& p) noexcept : ptr_(p.ptr_), count_(p.count_) {
        std::cout << "move" << std::endl;
        p.ptr_ = nullptr;
        p.count_ = nullptr;
    }

    // copy and swap
    shared_ptr& operator=(shared_ptr p) noexcept {
        using std::swap;
        swap(*this, p);
        return *this;
    }

    template<class U>
    shared_ptr& operator=(shared_ptr<U> &&p) noexcept {
        using std::swap;
        swap(*this, p);
        return *this;
    }

public:
    size_t use_count() const {
        if (count_) {
            return count_->get_count();
        } else {
            return 0;
        }
    }

    pointer get() const {return ptr_;}

    reference operator*() const {return *ptr_;}

    pointer operator->() const {return ptr_;}
};


template<class T, typename ...Args>
shared_ptr<T> make_shared(Args&& ...args) {
    auto ptr = new T(std::forward<Args>(args)...);
    return shared_ptr<T>(ptr);
}

} // namespace ptr