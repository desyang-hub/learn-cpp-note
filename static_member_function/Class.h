/**
 * @FilePath     : /learn-cpp-note/static_member_function/Class.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 11:14:03
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 11:15:06
**/
#pragma once

#include <iostream>

class Class
{
public:
    static void ShowInfo() {
        std::cout << "class name: Class" << std::endl;
    }
};
