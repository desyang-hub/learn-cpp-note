#ifndef __COMPOSITE__
#define __COMPOSITE__

#include <vector>
#include "component.h"
#include "primitive.h"

class Composite : public Component {
public:
    void add(Component* comp) {
        m_comps.push_back(comp);
    }

    Composite(const int& value) : Component(value) {}
private:
    std::vector<Component*> m_comps;
};

#endif