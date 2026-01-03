#include "complex.h"

using namespace std;

int main() {
    complex c1(1, 2), c2(3, 4);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    cout << c1 + c2 << endl;
    cout << 1 + c2 << endl;
    cout << c1 + 1 << endl;

    cout << c1 - c2 << endl;
    cout << 1 - c2 << endl;
    cout << c1 - 1 << endl;

    cout << c1 << endl;
    cout << comjugate(c1) << endl;

    c1 += c2;
    cout << c1 << endl;


    return 0;
}