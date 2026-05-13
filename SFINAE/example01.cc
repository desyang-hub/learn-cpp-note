#include <iostream>

struct A {
    using value_type = int;
};

struct B {};

template<class T>
void func(typename T::value_type*)
{
    std::cout << "Has attr value_type" << std::endl;
}

template<class T>
void func(T*)
{
    std::cout << "Not has attr value_type" << std::endl;
}




int main(int argc, char const *argv[])
{

    func<A>(nullptr);
    func<B>(nullptr);
    
    return 0;
}
