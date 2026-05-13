#include <iostream>

template<class T>
struct is_class_trait {
    struct two {
        char a; char b;
    };

    template<class U>
    static char test(int U::*);

    template<class U>
    static two test(...);

    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(char));
};

template<class T>
inline constexpr bool is_class_v = is_class_trait<T>::value;

int main(int argc, char const *argv[])
{
    
    std::cout << is_class_v<std::string> << std::endl;
    std::cout << is_class_v<int> << std::endl;

    return 0;
}
