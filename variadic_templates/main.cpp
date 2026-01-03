#include <iostream>

using namespace std;

void print() {
}

template<typename T, typename... Types>
void print(const T& t, const Types&... types) {
    cout << t << endl;
    print(types...);
}

int main() {

    print ('h', "hh", 1, 1.2);
    return 0;
}