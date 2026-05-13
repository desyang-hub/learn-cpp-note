#include <iostream>

using namespace std;

class Integer {
private:
    int data;
public:
    explicit Integer(int data=0) : data(data) {}

    // 默认就是前++
    Integer& operator++() {
        std::cout << "++obj" << std::endl;
        ++data;
        return *this;
    }

    // 这个版本尽量不用
    Integer operator++(int) { // 直接看函数名就知道 ++int == ++5 所以是前++
        std::cout << "obj++" << std::endl;

        auto val = data;
        ++data;
        return Integer(val);
    }
};

int main(int argc, char const *argv[])
{
    
    Integer i(2);

    ++i;
    i++;

    return 0;
}
