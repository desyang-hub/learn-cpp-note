#include <iostream>
#include <omp.h>
#include <vector>

int main(int argc, char const *argv[])
{
    const int N = 100;
    std::vector<int> data(N);

// 并行初始化
#pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        data[i] = i * i;
    }
    
    // 串行打印结果
    for (int i = 0; i < N; ++i) {
        std::cout << data[i] << std::endl;
    }


    return 0;
}
