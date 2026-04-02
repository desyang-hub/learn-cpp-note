#pragma once

namespace ptr
{

class nonecopyable
{
protected:
    // 禁止拷贝构造和拷贝赋值
    nonecopyable(const nonecopyable&) = delete;
    nonecopyable& operator=(const nonecopyable&) = delete;

protected:
    nonecopyable() = default;
    virtual ~nonecopyable() = default;
};
    
} // namespace ptr

