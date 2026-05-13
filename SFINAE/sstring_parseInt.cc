#include <sstream>
#include <iostream>

using namespace std;

int StringToInt(const std::string& s) {
    std::stringstream ssm(s);
    int value;
    ssm >> value;
    return value;
}

template<class T>
T StringParse(const std::string& s) {
    T v;
    std::stringstream ssm(s);
    
    ssm >> v;
    return v;
}

int main(int argc, char const *argv[])
{

    int num = StringToInt("820.1");
    std::cout << num << std::endl;

    int num1 = stoi("123");
    std::cout << num1 << std::endl;

    double num_double = StringParse<double>("3.1515926");
    std::cout << num_double << std::endl;
    
    return 0;
}
