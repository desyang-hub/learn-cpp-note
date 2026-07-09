// private_shared.cpp
#include <iostream>
#include <omp.h>

int main() {
    int shared_var = 0;
    
    #pragma omp parallel private(shared_var)  // 每个线程有自己的副本
    {
        int thread_id = omp_get_thread_num();
        shared_var = thread_id;  // 修改的是私有副本
        std::cout << "Thread " << thread_id 
                  << " shared_var = " << shared_var << std::endl;
    }
    
    // 共享变量未被修改
    std::cout << "After parallel: shared_var = " << shared_var << std::endl;
    
    return 0;
}