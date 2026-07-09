// reduction.cpp
#include <iostream>
#include <omp.h>

int main() {
    int sum = 0;
    const int N = 1000;
    
    // 串行版本
    for (int i = 0; i < N; ++i) {
        sum += i;
    }
    std::cout << "Serial sum: " << sum << std::endl;
    
    // 并行版本（使用reduction）
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += i;  // 每个线程有私有副本，最后合并
    }
    std::cout << "Parallel sum: " << sum << std::endl;
    
    // 其他reduction操作
    int max_val = 0;
    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < 100; ++i) {
        if (i > max_val) max_val = i;
    }
    std::cout << "Max: " << max_val << std::endl;
    
    return 0;
}