#pragma once

#include <iostream>


template<class T>
void print(T&& t) {
    std::cout << std::forward<T>(t) << std::endl;
}

#ifdef LOG_LEVEL
    #define LOG(arg) print(arg);
#else
    #define LOG(arg) void();
#endif