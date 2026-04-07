#include <iostream>

using namespace std;

void process(const int& lvalue) {
    std::cout << "lvalue: " << lvalue << std::endl;
}

void process(int&& rvalue) {
    std::cout << "rvalue: " << rvalue << std::endl;
}

// 完美转发
template<class T>
void process_forward(T&& value) {
    std::cout << "forword" << std::endl;
    process(std::forward<T>(value));
}

int main() {
    int lvalue = 7;
    process(lvalue);

    process(8);

    process_forward(lvalue);
    process_forward(8);

    process(std::move(lvalue));

    

    return 0;
}