#include "TimeStamp.h"

#include <iostream>

int main() {

    auto time_now = utils::TimeStamp::Now();

    std::cout << time_now << std::endl;

    std::cout << "Time Now: " << time_now.toString() << std::endl;


    return 0;
}