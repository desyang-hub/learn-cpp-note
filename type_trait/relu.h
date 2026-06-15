/**
 * @FilePath     : /learn-cpp-note/type_trait/relu.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-15 12:03:42
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-15 15:38:30
**/
#pragma once

#include "layer.h"
#include "layer_wrapper.h"

template<class T>
class Relu : public Layer<T>
{
public:
    // using value_type = T;

    Relu(/* args */) = default;
    ~Relu() = default;

    std::string type() const override;
};



template<class T>
std::string Relu<T>::type() const {
    return "nn.ReLU";
}

LayerWrapper<Relu<float>> g_relu_register("nn.ReLU");