#pragma once

#include <iostream>

class Array {

private:
    void release() {
        if (arr_) {
            delete[] arr_;
            arr_ = nullptr;
        }
            
    }
public:
    Array(size_t size) : arr_(new int[size]), size_(size) {
    }

    ~Array() {
        release();
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    // 简单的移动构造实现
    Array(Array&& arr) : arr_(arr.arr_) {
        arr.arr_ = nullptr; // 资源转移并重置
    }

    Array& operator=(Array&& arr) {
        // 判断自赋值
        if (&arr != this) {
            release();
            arr_ = arr.arr_;
            arr.arr_ = nullptr;
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

private:
    int* arr_;
    size_t size_;
};