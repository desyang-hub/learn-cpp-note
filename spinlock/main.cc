#include "spinlock.h"

#include <iostream>
#include <mutex>
#include <vector>

int g_spinlock_shared = 0;
lock::SpinLock g_splock;

// 自旋锁样例程序
void spinlock_worker(int id) {
    for (int i = 0; i < 1000; ++i) {
        g_splock.lock();
        ++g_spinlock_shared;
        g_splock.unlock();
    }
}

int g_mutext_shared = 0;
std::mutex g_mutex;

// 互斥锁样例程序
void mutex_worker(int id) {
    for (int i = 0; i < 1000; ++i) {
        g_mutex.lock();
        ++g_mutext_shared;
        g_mutex.unlock();
    }
}

int main() {

    std::vector<std::thread> splock_threads;
    splock_threads.reserve(10);

    for (int i = 0; i < 10; ++i) {
        splock_threads.emplace_back(spinlock_worker, i);
    }


    std::vector<std::thread> mutex_threads;
    mutex_threads.reserve(10);
    for (int i = 0; i < 10; ++i) {
        mutex_threads.emplace_back(mutex_worker, i);
    }

    for (int i = 0; i < 10; ++i) {
        splock_threads[i].join();
        mutex_threads[i].join();
    }

    std::cout << "splock_result: " << g_spinlock_shared << std::endl;
    std::cout << "mutex_result: " << g_mutext_shared << std::endl;


    return 0;
}