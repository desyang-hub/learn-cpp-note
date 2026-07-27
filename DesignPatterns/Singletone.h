#pragma once

#include <iostream>

#include "nonecopyable.h"

class Singletone : public nonecopyable
{
private:
    Singletone() = default;
public:
    ~Singletone() = default;

    void say() const {
        std::cout << "singletone mode" << std::endl;
    }

    static Singletone& GetInstance() {
        static Singletone instance;
        return instance;
    }
};

inline void singletone_demo() {
    // 单例模式下提供一个静态函数获取唯一实例，构造函数设置为私有，不可拷贝和移动
    Singletone& a = Singletone::GetInstance();
    a.say();
}