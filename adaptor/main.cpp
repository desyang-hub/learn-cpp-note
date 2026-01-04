#include <iostream>
#include <vector>
#include <list>

#include <algorithm>
#include "insertor.hpp"

using namespace std;

int main() {

    int myint[] = {6, 7, 8, 9, 10};
    vector<int> myvec(5);
    copy(myint, myint + 5, myvec.begin());

    std::for_each(myvec.begin(), myvec.end(), [](const int& item) {
        cout << item << endl;
    });

    cout << endl;

    // 现有一个要求，接口不变实现insertor copy, 此处需要实现一个适配器用于实现这个copy insertor适配
    list<int> ls{1, 2, 3, 4, 5};
    auto iter = ls.begin();
    ls.insert(iter, 1);
    std::advance(iter, 2);
    copy(myvec.begin(), myvec.end(), adaptors::insertor_adaptor(ls, iter));
    // ls.insert
    std::for_each(ls.begin(), ls.end(), [](const int& item) {
        cout << item << endl;
    });




    return 0;
}