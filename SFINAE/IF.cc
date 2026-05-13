#include <iostream>

using namespace std;

template<bool v, class THEN, class ELSE>
struct IF {

};

template<class THEN, class ELSE>
struct IF<true, THEN, ELSE> {
    using RES = THEN;
};

template<class THEN, class ELSE>
struct IF<false, THEN, ELSE> {
    using RES = ELSE;
};

template<int num>
struct is_even : public IF<!(num&1), std::true_type, std::false_type> {
};

template<int num>
inline constexpr bool is_even_v = is_even<num>::RES::value;

int main(int argc, char const *argv[])
{
    
    std::cout << is_even_v<1> << std::endl;

    std::cout << is_even_v<2> << std::endl;
    
    return 0;
}
