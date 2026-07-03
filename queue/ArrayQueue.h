/**
 * @FilePath     : /learn-cpp-note/queue/ArrayQueue.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 13:01:02
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 14:16:32
**/
#pragma once

#include <cstddef>
#include <memory>
#include <cstring>

template<class T>
class ArrayQueue
{
private:
    std::unique_ptr<T[]> arr;
    size_t size_;
    size_t head_;
    size_t tail_;
    size_t capacity_;

    void expand(size_t new_cap) {
        std::unique_ptr<T[]> new_arr(new T[new_cap]);

        // ✅ 使用 std::uninitialized_move 替代 memcpy，支持非平凡类型
        // 环形缓冲区可能分两段存储，需要分别移动
        size_t first_seg = (capacity_ - head_) < size_ 
                         ? (capacity_ - head_) 
                         : size_;
        
        std::uninitialized_move_n(arr_.get() + head_, first_seg, new_arr.get());
        
        if (first_seg < size_) {
            std::uninitialized_move_n(arr_.get(), size_ - first_seg, 
                                      new_arr.get() + first_seg);
        }

        arr_ = std::move(new_arr);
        head_ = 0;
        tail_ = size_;
        capacity_ = new_cap;
    }

    

public:
    ArrayQueue(size_t cap = 10) : 
        size(0), arr(new T[size]), is_full(false), head_(0), tail_(0), capacity_(cap) {
    }
    ~ArrayQueue() = default;

    // ✅ 禁止拷贝和移动
    ArrayQueue(const ArrayQueue&) = delete;
    ArrayQueue& operator=(const ArrayQueue&) = delete;
    ArrayQueue(ArrayQueue&&) = delete;
    ArrayQueue& operator=(ArrayQueue&&) = delete;

    void push(const T& val) {
        if (size == capacity_) {
            expand(capacity_ * 2);
        }

        arr[tail_++] = val;
        tail_ %= capacity_;
        ++size;
    }

    void push(T&& val) {
        if (size == capacity_) {
            expand(capacity_ * 2);
        }

        arr[tail_] = std::move(val);
        tail_ = (tail_ + 1) % capacity_;
        ++size;
    }

    bool pop(T& val) {
        if (size == 0) return false;
        is_full = false;
        val = arr[head_];
        head_ = (head_ + 1) % capacity_;
        --size;

        return true;
    }

    size_t size() const {
        return size_;
    }
    
    bool empty() const {
        return size_ == 0;
    }
};