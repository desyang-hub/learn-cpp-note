#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.emplace_back(3);

    list<int>::iterator iter = ls.begin();

    std::copy()

    // list 不具备随机访问能力，其iterator无+=操作，通过advance(iter, n),来将迭代器向前移动n次
    std::advance(iter, 2);
    cout << *iter << endl;

    return 0;
}