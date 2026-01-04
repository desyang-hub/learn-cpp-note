#pragma once

/**

copy(first, last, dst)

while (first != last) {
    *fisrt = *dst;
    ++first;
    ++dst;
}

 */
#include <iostream>

using std::cout;
using std::endl;


namespace adaptors {

// 一个insert iterator 重载原有的copy操作
template<typename Container>
class insert_iterator {
public:
    typedef typename Container::iterator iterator_type;
    typedef typename Container::value_type value_type;
    insert_iterator(Container& c, const iterator_type& iter) : _m_c(&c), _m_iter(iter) {}

    insert_iterator& operator=(const value_type& value) {
        // list insert插入方式是，指定一个iter，一直往这个iter的上一个元素进行插入
        _m_c->insert(_m_iter, value);
        return *this;
    }

    // 以下操作符必须存在，但可为空操作
    insert_iterator& operator*()     { return *this; }
    insert_iterator& operator++()    { return *this; }
    insert_iterator& operator++(int) { return *this; }

private:
    Container* _m_c;
    iterator_type _m_iter;
};

// 一个函数用于封装insertor iterator
template<class Container>
insert_iterator<Container> insertor_adaptor(Container& c, const typename Container::iterator& iter) {
    return insert_iterator<Container>(c, iter);
}


} // namespace adaptors end