#include <iostream>
#include <functional>

template<class F, typename ...Args>
using invoke_result_t = typename std::invoke_result<F, Args...>::type;

template<class F, typename ...Args, 
    std::enable_if_t<std::is_void<invoke_result_t<F, Args...>>::value, int> = 0>
void call(F&& f, Args&& ...args) {
    std::cout << "Call void(Args...)" << std::endl;
    std::bind(std::forward<F>(f), std::forward<Args>(args)...)();
}

template<class F, typename ...Args, 
    std::enable_if_t<!std::is_void<invoke_result_t<F, Args...>>::value, int> = 0>
invoke_result_t<F, Args...> call(F&& f, Args&& ...args) {
    std::cout << "Call Any(Args...)" << std::endl;
    return std::bind(std::forward<F>(f), std::forward<Args>(args)...)();
}

void f_void(){}
int f_int(int a) {
    return a;
}


int main(int argc, char const *argv[])
{

    call(f_void);
    call(f_int, 1);
    
    return 0;
}
