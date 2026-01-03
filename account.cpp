#include <iostream>

using namespace std;

class Bank {
public:
    static double rate;
    static void set_rate(const double& r) {
        rate = r;
    }
};
double Bank::rate = 2;

int main() {

    Bank::rate = 10;
    Bank::set_rate(2);

    cout << Bank::rate << endl;

    return 0;
}