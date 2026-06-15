#include "relu.h"
#include "layer_wrapper.h"

#include <iostream>
#include <vector>

template<class T = int>
class lines : public std::vector<T> {
public:
    lines() {
    }
};

int main(int argc, char const *argv[])
{

    lines<int> line;
    line.push_back(1);
    lines<int>::iterator it = line.begin();
    std::cout << *it << std::endl;

    
    auto types =  LayerRegisterer<float>::ListTypes();
    for (auto& type : types) {
        std::cout << type << std::endl;
    }


    return 0;
}
