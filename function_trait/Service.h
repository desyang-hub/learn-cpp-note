/**
 * @FilePath     : /learn-cpp-note/function_trait/Service.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-18 10:50:38
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-18 11:44:22
**/
#pragma once

#include "function_trait.h"
#include <iostream>
#include <tuple>
#include "tuple_printer.h"

// 这里我需要通过解析方式来将正常的方法进行代理，改变其行为，或者说，此处头文件只提供声明，并没有定义，但是通过魔法宏+type trait生成同名的方法

// 通过类名和方法，来推导其真实的函数特征
#define PROXY_METHOD_BIND(Class, Method) \
    public: \
    class Proxy {   \
        public: \
        using MethodType_##Method = decltype(&Class::Method);   \
        using MethodReturnType_##Method = typename function_trait<MethodType_##Method>::return_type;    \
        \
        template<class... Args>  \
        MethodReturnType_##Method Method(Args&& ...args) { \
            std::cout << "Invoke proxy function => " << #Class "::" #Method;  \
            if constexpr (sizeof...(Args) == 0) { \
                std::cout << "(void)" << std::endl;    \
            } else { \
                print(std::make_tuple<Args...>(std::forward<Args>(args)...)); \
            } \
        }   \
    };  \
    private:

class Service
{
public:
    bool isServiceRunning();

    void startService();

    void stopService();

    void func(int a, double b, const char* str);

    PROXY_METHOD_BIND(Service, func);
};


