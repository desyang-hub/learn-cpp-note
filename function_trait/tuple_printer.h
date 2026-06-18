/**
 * @FilePath     : /learn-cpp-note/function_trait/tuple_printer.h
 * @Description  :  
 * @Author       : desyang
 * @Date         : 2026-06-18 11:03:05
 * @LastEditors  : desyang
 * @LastEditTime : 2026-06-18 11:27:34
**/
#pragma once

#include <stddef.h>
#include <tuple>

template<class Tuple, size_t N>
struct tuple_printer {
    static void print(const Tuple& t) {
        tuple_printer<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};


template<class Tuple>
struct tuple_printer<Tuple, 1> {
    static void print(const Tuple& t) {
        std::cout << std::get<0>(t);
    }
};


template<class ...Args>
void print(const std::tuple<Args...>& t) {
    std::cout << "(";
    constexpr size_t args_nums = sizeof...(Args);
    tuple_printer<std::tuple<Args...>, args_nums>::print(t);
    std::cout << ")" << std::endl;
}