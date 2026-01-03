#include <iostream>

using namespace std;

typedef struct Stag {
    int a, b, c, d;
} S;

int main() {
    int x = 0;
    int* p = &x;
    int &rx = x;

    cout << sizeof(x) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(rx) << endl;

    cout << p << endl;
    cout << &x << endl;
    cout << &rx << endl;
    cout << x << endl;
    cout << rx << endl;

    S s;
    S& rs = s;

    cout << sizeof(s) << endl;
    cout << sizeof(rs) << endl;
    cout << &s << endl;
    cout << &rs << endl;
    

    return 0;
}