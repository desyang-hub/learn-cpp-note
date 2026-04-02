#include <iostream>
#include <vector>

using namespace std;

class Integer {
public:
    Integer(int val=0) : val_(val) {
        cout << "Integer::Integer() param val=" << val << endl;
    }

    ~Integer() {
        cout << "Integer::~Integer() param val=" << val_ << endl;
    }

    operator int() const {
        return val_;
    }

    int val() const {
        return val_;
    }
private:
    int val_;
};

int main() {

    vector<Integer> nums;
    // nums.reserve(10);
    nums.resize(10);

    return 0;
}