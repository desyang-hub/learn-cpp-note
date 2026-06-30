/**
 * @FilePath     : /learn-cpp-note/RAII/FILEGuarder.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-30 10:29:21
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-30 10:29:22
**/
#pragma once

#include <iostream>

namespace RAII
{

struct FILEGuarder {
    void operator()(FILE* file) const {
        if (file) {
            fclose(file);
        }
    }
};
    
    
} // namespace RAII
