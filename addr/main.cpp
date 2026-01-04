#include <iostream>

using namespace std;

int main() {

    auto p = std::pair<int, int>{1, 2};
    auto addr = &p;
    cout << addr << endl;

    auto a1 = &"abcd";
    cout << (char*)a1 << endl;
    char* str = (char*)a1;
    str[0] = 'b';
    cout << str << endl;




    return 0;
}