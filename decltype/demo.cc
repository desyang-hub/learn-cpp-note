#include <iostream>
#include <string>
#include <functional>

using namespace std;

template<class R>
auto returnType(std::function<R()> f) -> decltype(f()) {
    return f();
}

template<class F, typename ...Args>
auto call(F&& f, Args&& ...args) -> decltype(f(std::forward<Args>(args)...)) {
    return f(std::forward<Args>(args)...);
}

int test() {
    return 7;
}

int main() {

    auto t = call(test);
    cout << t << endl;

    return 0;
}