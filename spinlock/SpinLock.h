#pragma once

#include <atomic>

class SpinLock
{
private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
public:
    SpinLock(/* args */);
    ~SpinLock();

public:
    void lock() {
        while (flag_.test_and_set(std::memory_order_acquire)) {
            // busy-wait
            
        }
    }

    void unlock() {
        flag_.clear(std::memory_order_release);
    }
};

SpinLock::SpinLock(/* args */)
{
}

SpinLock::~SpinLock()
{
}
