//
// Created by Bartek on 22.05.2018.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <utility>
#include <iostream>

namespace factoryMethod{
    template <typename T>
    T Create(){
        T a;
        return a;
    }

    class MyType{
    public:
        MyType();
        ~MyType();
        std::string SayHello();
    std::string value;


        template <typename T>
                T Add(T first, T second){
            return first + second;
        }
    };


}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
