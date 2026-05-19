#include <iostream>

using namespace std;

class Employ{};

class Holder : public Employ {
    int x;
};


int main(int argc, char const *argv[])
{
    std::cout << sizeof(Employ) << std::endl;
    std::cout << sizeof(Holder) << std::endl;
    

    return 0;
}
