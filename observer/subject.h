#ifndef __SUBJECT__
#define __SUBJECT__

#include <vector>
#include "observer.h"

class Subject {
public:
    void attach(Observer *sub) {
        m_observers.push_back(sub);
    }

    void set_value(int value) {
        m_value = value;
        notify();
    }

    void notify() {
        for (auto obs : m_observers) {
            obs->update(this, m_value);
        }
    }

private:
    std::vector<Observer*> m_observers;
    int m_value;
};

#endif