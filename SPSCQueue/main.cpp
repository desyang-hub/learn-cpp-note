/**
 * @FilePath     : /learn-cpp-note/SPSCQueue/main.cpp
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-15 10:35:48
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-15 10:56:32
**/
#include "SPSCQueue.hpp"
#include <thread>
#include <unistd.h>
#include <iostream>

SPSCQueue<size_t> que;
std::atomic<bool> is_close_{false};

void Productor() {
    for (int i = 0; i < 5; ++i) {
        // sleep(2);
        while (!que.push(i));
    }
}

void Consumer() {
    size_t d;
    while (!is_close_) {
        bool is_success = que.pop(d);
        if (is_success) {
            std::cout << "Consume value: " << d << std::endl;
        }
    }

}

int main(int argc, char const *argv[])
{
    
    std::thread productor(Productor);
    std::thread consumer(Consumer);

    if (productor.joinable())
        productor.join();

    if (consumer.joinable())
        consumer.join();

    return 0;
}
