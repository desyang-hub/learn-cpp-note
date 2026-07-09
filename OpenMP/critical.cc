// critical.cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> results;
    results.reserve(100);
    
    #pragma omp parallel for
    for (int i = 0; i < 100; ++i) {
        int result = i * i;
        
        // 临界区：一次只有一个线程执行
        #pragma omp critical
        {
            results.push_back(result);
        }
    }
    
    std::cout << "Results size: " << results.size() << std::endl;
    return 0;
}