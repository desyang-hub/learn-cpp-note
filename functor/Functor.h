/**
 * @FilePath     : /learn-cpp-note/functor/Functor.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 11:00:09
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 11:04:00
**/
#pragma once

#include <iostream>

struct Functor {
    virtual void operator()() {
        std::cout << "Functor::operator()" << std::endl;
    }
};