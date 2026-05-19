#include <iostream>
#include <vector>

using namespace std;

template<
template<class, class>
class Container = vector, 
class F,
class R>
auto fmap(F&& f, R&& input) {
    using result_type = decay_t<decltype(f(input.front()))>;
    Container<result_type, std::allocator<result_type>> c;

    for (auto&& item : input) {
        c.push_back(f(item));
    }

    return c;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4};
    auto adder = [](int item){ return item + 1;};
    
    auto res = fmap(adder, v);

    for (auto& item : res) {
        std::cout << item << std::endl;
    }

    return 0;
}
