// schedule.cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <thread>

void work(int id) {
    // 模拟不同工作负载
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * (id % 3 + 1)));
}

int main() {
    const int N = 20;
    
    std::cout << "=== Static Schedule ===" << std::endl;
    #pragma omp parallel for schedule(static, 4) num_threads(4)
    for (int i = 0; i < N; ++i) {
        int tid = omp_get_thread_num();
        printf("Thread %d processing iteration %d\n", tid, i);
        work(i);
    }
    
    std::cout << "\n=== Dynamic Schedule ===" << std::endl;
    #pragma omp parallel for schedule(dynamic, 2) num_threads(4)
    for (int i = 0; i < N; ++i) {
        int tid = omp_get_thread_num();
        printf("Thread %d processing iteration %d\n", tid, i);
        work(i);
    }
    
    std::cout << "\n=== Guided Schedule ===" << std::endl;
    #pragma omp parallel for schedule(guided, 2) num_threads(4)
    for (int i = 0; i < N; ++i) {
        int tid = omp_get_thread_num();
        printf("Thread %d processing iteration %d\n", tid, i);
        work(i);
    }
    
    return 0;
}