// array_calc.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
    const int N = 100000000;  // 1亿个元素
    std::vector<float> a(N), b(N), c(N);
    
    // 初始化数据
    for (int i = 0; i < N; ++i) {
        a[i] = i * 0.1f;
        b[i] = i * 0.2f;
    }
    
    // 串行版本
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Serial time: " << duration.count() << " ms" << std::endl;
    
    // 并行版本
    start = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Parallel time: " << duration.count() << " ms" << std::endl;
    
    return 0;
}