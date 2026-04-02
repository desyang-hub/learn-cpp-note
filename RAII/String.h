#pragma once

#include <iostream>

namespace RAII
{

class String final
{
private:
    char* ptr_;
public:
    explicit String(const char* ptr = nullptr);
    ~String();

    // 这里简化就去除拷贝和移动
    String(const String&) = delete;
    String& operator=(const String&) = delete;

    // 这里简化就去除拷贝和移动
    String(String&&) = delete;
    String& operator=(String&&) = delete;

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        return os << str.ptr_;
    }
};

    
} // namespace RAII
