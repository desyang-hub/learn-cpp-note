#pragma once

#include <iostream>
#include <time.h>
#include <string>

namespace utils
{

class TimeStamp
{
private:
    time_t micorSecondSinceEpoch_;
public:

    TimeStamp(uint64_t micorSecondSinceEpoch) : micorSecondSinceEpoch_(micorSecondSinceEpoch) {}

public:

    std::string toString() const {
        tm* local_time = localtime(&micorSecondSinceEpoch_);

        char buf[64];
        snprintf(buf, 64, "%04d/%02d/%02d %02d:%02d:%02d", local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

        return buf;
    }

    static TimeStamp Now() {
        return TimeStamp(time(nullptr));
    }

    friend std::ostream& operator<<(std::ostream& os, const TimeStamp& timeStamp) {
        return os << timeStamp.toString();
    }

};
    
} // namespace utils
