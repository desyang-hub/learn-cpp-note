/**
 * @FilePath     : /learn-cpp-note/SPSCQueue/SPSCQueue.hpp
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-15 10:22:46
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-15 10:58:41
**/
#pragma once

#include <atomic>
#include <vector>
#include <stdint.h>
#include <stddef.h>
#include <iostream>

template<class T>
class SPSCQueue
{
private:
    std::atomic<size_t> head_{0};
    std::atomic<size_t> tail_{0};
    size_t capacity_{0};
    size_t mask_;
    std::vector<T> queue_;
public:
    SPSCQueue(size_t capacity = 1024);
    ~SPSCQueue();

    bool push(const T& val);
    bool pop(T& val);
};

template<class T>
SPSCQueue<T>::SPSCQueue(size_t capacity) : capacity_(capacity), mask_(capacity - 1), queue_(capacity)
{
}

template<class T>
SPSCQueue<T>::~SPSCQueue()
{
}

template<class T>
bool SPSCQueue<T>::push(const T& val) {
    // 取出变量
    size_t current_tail = tail_.load(std::memory_order_relaxed);
    size_t next_tail = (current_tail + 1) & mask_;

    if (next_tail == head_.load(std::memory_order_release)) {
        return false; // 队列满
    }

    queue_[current_tail] = val;

    tail_.store(next_tail, std::memory_order_acquire);

    return true;
}

template<class T>
bool SPSCQueue<T>::pop(T& val) {
    size_t current_head = head_.load(std::memory_order_relaxed);

    if (current_head == tail_.load(std::memory_order_release)) {

        return false;
    }

    val = queue_[current_head];
    std::cout << "pop val: " << val << std::endl;
    head_.store((current_head + 1) & mask_, std::memory_order_acquire);

    return true;
}