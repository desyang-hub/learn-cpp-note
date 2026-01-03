#ifndef __PRIMITIVE__
#define __PRIMITIVE__

#include "component.h"

class Primitive : public Component {
public:
    Primitive(const int& value) : Component(value) {}
};

#endif