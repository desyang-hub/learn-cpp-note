#include <iostream>

template<class F, class ...Args>
using invoke_result_t = typename std::__invoke_result<F, Args...>::type;


template<class F, class ...Args>
auto call(F&& f, Args&& ...args) -> invoke_result_t<F, Args...> {
    return std::forward<F>(f)(std::forward<Args>(args)...);
}

void f() {
    std::cout << "Call void() function" << std::endl;
}

int f1(int n) {
    std::cout << "Call int(int) function" << std::endl;
    return n;
}

int main(int argc, char const *argv[])
{
    call(f);

    int n = call(f1, 1);
    std::cout << n << std::endl;
    return 0;
}
