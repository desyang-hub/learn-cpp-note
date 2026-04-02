#include <iostream>
#include <iterator>

using namespace std;

int main() {

    int arr[] = {1, 2, 3};

    std::ostream_iterator<int> out_s(std::cout, ",");

    std::copy(arr, arr + 3, out_s);

    return 0;
}