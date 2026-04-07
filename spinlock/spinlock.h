#pragma once

#include "lock.h"

#include <thread>
#include <atomic>

namespace lock
{

class SpinLock : public Locker
{
private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
public:
    void lock() override {
        // 忙等待，不断循环获取锁
        while(flag_.test_and_set(std::memory_order_acquire)) {
            // 可选优化，重度竞争让出CPU
            std::this_thread::yield();
        }
    }

    void unlock() override {
        // 释放锁
        flag_.clear(std::memory_order_release);
    }
};

    
} // namespace lock
