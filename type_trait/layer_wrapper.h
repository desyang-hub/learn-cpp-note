/**
 * @FilePath     : /learn-cpp-note/type_trait/layer_wrapper.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-15 12:03:19
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-15 15:38:19
**/
#pragma once

#include "layer.h"
#include <vector>
#include <functional>
#include <map>
#include <stdexcept>


template <typename T>
class LayerRegisterer {
 public:
  using Creator = std::function<Layer<T>*(void)>;

  /**
   * Register a creator function for the given type string.
   * Returns true on success, false if the name is already registered.
   */
  static bool RegisterCreator(const std::string& type, Creator creator) {
    auto& registry = GetRegistry();
    if (registry.count(type)) {
      return false;  // already registered
    }
    registry[type] = std::move(creator);
    return true;
  }

  /**
   * Create a Layer<T> instance by type string.
   * Throws std::runtime_error if the type is not found.
   */
  static Layer<T>* CreateLayer(const std::string& type) {
    auto& registry = GetRegistry();
    auto it = registry.find(type);
    if (it == registry.end()) {
      throw std::runtime_error(
          "LayerRegisterer::CreateLayer: unknown type \"" + type + "\"");
    }
    return it->second();
  }

  /**
   * Check whether a type string has been registered.
   */
  static bool HasType(const std::string& type) {
    auto& registry = GetRegistry();
    return registry.count(type) > 0;
  }

  /**
   * List all registered type names (for debugging/introspection).
   */
  static std::vector<std::string> ListTypes() {
    auto& registry = GetRegistry();
    std::vector<std::string> types;
    types.reserve(registry.size());
    for (auto& p : registry) {
      types.push_back(p.first);
    }
    return types;
  }

 private:
  static std::map<std::string, Creator>& GetRegistry() {
    static std::map<std::string, Creator> registry;
    return registry;
  }
};

template<class L> // L 是layer的类型，而数据类型需要通过type_trait来获取
class LayerWrapper
{
    using T = typename L::value_type;
public:
    LayerWrapper(const std::string& type);
    ~LayerWrapper();
};

template<class L>
LayerWrapper<L>::LayerWrapper(const std::string& type)
{
    LayerRegisterer<T>::RegisterCreator(type, []() -> Layer<T>* {
        return new L();
    });
}

template<class T>
LayerWrapper<T>::~LayerWrapper()
{
}
