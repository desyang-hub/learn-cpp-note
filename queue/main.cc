#include <iostream>
#include "ThreadSafeQueue.h"
#include <vector>

#include <thread>

int main(int argc, char const *argv[])
{
    
    ThreadSafeQueue<int> que;

    int num_thread = 10;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_thread; ++i) {
        threads.emplace_back([&que, i]{
            for (int j = 0; j <= i; ++j)
                que.push(j);
        });
    }

    for (int i = 0; i < num_thread; ++i) {
        threads[i].join();
    }

    int item;
    while (!que.empty()) {
        bool success = que.pop(item);
        if (success) {
            std::cout << item << std::endl;
        }
    }


    return 0;
}
