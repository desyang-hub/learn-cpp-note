#include <iostream>
#include <sstream>

using namespace std;

// python 2 * 'a' 2 * "aa"

namespace utils {
    std::string operator*(const std::string& str, int n) {
        std::stringstream ssm;
        while (n--) {
            ssm << str;
        }
        return ssm.str();
    }

    std::string operator*(int n, const std::string& str) {
        std::stringstream ssm;
        while (n--) {
            ssm << str;
        }
        return ssm.str();
    }
}
using namespace utils;


int main(int argc, char const *argv[])
{

    std::cout << "111"s * 2 << std::endl;
    std::cout << "aaa"s * 10 << std::endl;
    std::cout << "="s * 20 << std::endl;
    
    return 0;
}
