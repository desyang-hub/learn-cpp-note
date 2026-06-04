/**
 * @FilePath     : /learn-cpp-note/logger/Stream.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-04 19:51:13
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-04 20:33:08
**/
#pragma once

#include <sstream>
#include <cstdio>
#include <functional>

namespace {
    const auto stdio_stream_handler = [](const std::string& msg){
        printf("%s\n", msg.c_str());
    };
}

class Stream final
{
    using StreamHandler = std::function<void(const std::string&)>;
private:
    std::stringstream sstream_;
    StreamHandler streamHandler_;
public:
    explicit Stream(const char* buf, const StreamHandler& streamHandler = stdio_stream_handler) : sstream_(), streamHandler_(streamHandler) {
        sstream_ << buf;
    }
    ~Stream() {
        streamHandler_(sstream_.str());
    }

    template<class T>
    Stream& operator<<(const T& rhs) {
        sstream_ << rhs;
        return *this;
    }
};
