#include "thread_pool.h"

#include <iostream>

using namespace std;

int add_range(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b;  ++i) sum+= i;
    return sum;
}

int main(int argc, char const *argv[])
{

    thread_pool pool(8);

    int num = 1e4;

    std::vector<std::future<int>> results;
    results.reserve(num);

    for (int i = 0; i < num; ++i) {
        results.emplace_back(pool.enqueue(add_range, 0, i));
        // add_range(0, i);
        // int d = i + i + 1;
    }

    // for (auto& f : results) {
    //     cout << f.get() << std::endl;
    // }

    
    return 0;
}


int add(int a, int b) {
    return a + b;
}