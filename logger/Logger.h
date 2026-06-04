/**
 * @FilePath     : /learn-cpp-note/logger/Logger.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-04 19:45:36
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-04 20:38:26
**/
#pragma once

#include <stddef.h>
#include <functional>

#include "Stream.h"
#include "LogLevel.h"
#include "TimeStamp.h"

#define LOG_INFO Logger(__FILE__, __LINE__, INFO).ostream("INFO")

class Logger
{
private:
    const char* file_;
    size_t line_;
    int log_level_;
public:
    Logger(const char* file, size_t line, int log_level) : file_(file), line_(line), log_level_(log_level) {
    }
    ~Logger() {

    }

    Stream ostream(const char* log_level) {
        // 将日志信息存入到里面
        char buf[256];
        snprintf(buf, 256, "%s:%lu %s ", file_, line_, log_level);

        return Stream(buf);
    }
};