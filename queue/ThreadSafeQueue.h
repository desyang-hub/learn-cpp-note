/**
 * @FilePath     : /learn-cpp-note/queue/ThreadSafeQueue.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 11:20:52
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 11:51:23
**/
#pragma once

// 实现一个线程安全队列
#include <mutex>
#include <condition_variable>
#include <queue>

template<class T>
class ThreadSafeQueue
{
private:
    mutable std::mutex mutex_;
    std::condition_variable condition_;
    std::queue<T> que_;

    bool is_close_;

public:
    ThreadSafeQueue() : is_close_(false) {}
    ~ThreadSafeQueue() {
        this->close();
    }

    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue(ThreadSafeQueue&&) = delete;
    ThreadSafeQueue& operator=(ThreadSafeQueue&&) = delete;

    void close() {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (is_close_) return;
            is_close_ = true;
        }
        condition_.notify_all();
    }


    // 
    bool push(const T& val) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (is_close_) return false;
            que_.push(val);
        }
        condition_.notify_one();
        return true;
    }

    bool push(T&& val) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (is_close_) return false;
            que_.push(std::move(val));
        }
        condition_.notify_one();
        return true;
    }

    bool pop(T& val) {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            condition_.wait(lock, [this]{
                return !que_.empty() || is_close_;
            });

            if (que_.empty()) return false;
            val = std::move(que_.front());
            que_.pop();
            return true;
        }

        return true;
    }

    bool try_pop(T& val) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (que_.empty()) return false;

            val = std::move(que_.front());
            que_.pop();
        }
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return que_.empty();
    }
};