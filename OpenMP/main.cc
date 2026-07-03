#include <iostream>
#include <omp.h>

int main(int argc, char const *argv[])
{
    
    // 设置线程数量
    omp_set_num_threads(4);

#pragma omp parallel
    {
        // 获取线程编号
        size_t thread_id = omp_get_thread_num();
        size_t number_thread = omp_get_num_threads();

        std::cout << "thread id: " << thread_id << " of " << number_thread << std::endl;
    }

    std::cout << "All thread finish!" << std::endl;

    return 0;
}
