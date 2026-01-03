#ifndef __COMPONENT__
#define __COMPONENT__

class Component {
public:
    virtual void add(Component *c) {

    }

    Component(const int& value=0) : m_value(value) {}

    virtual ~Component() {}
private:
    int m_value;
};

#endif