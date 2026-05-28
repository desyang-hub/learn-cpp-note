#pragma once

class nonecopyable
{
public:
    nonecopyable() = default;
    ~nonecopyable() = default;

    // 禁用拷贝
    nonecopyable(const nonecopyable&) = delete;
    nonecopyable& operator=(const nonecopyable&) = delete;
};
