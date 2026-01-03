#include <iostream>
#include "fraction.h"

using namespace std;


int main() {
    Fraction a(1, 4);

    cout << double(a) << endl;

    double d = 3 + a;

    cout << d << endl;

    cout << string(a) << endl;

    return 0;
}