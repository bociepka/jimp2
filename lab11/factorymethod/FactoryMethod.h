//
// Created by Bartek on 22.05.2018.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <utility>
#include <iostream>
#include <complex>
#include <vector>
#include <numeric>
#include <algorithm>

namespace factoryMethod{
    template <typename T>
    T Create(){
        T a{};
        return a;
    }

    class MyType{
    public:
        MyType();
        ~MyType();
        std::string SayHello();
    std::string value;

    };

    template <typename T>
    T Add(T first, T second){
        return first + second;
    }

    template <typename T>
    T Mean(std::vector<T> vec){
        T result = (std::accumulate(vec.begin(), vec.end(), 0.0))/vec.size();
        return result;
    }

    template <typename T>
    auto Value(const T& p){
        return *(p);
    }
    }


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
