//
// Created by Bartek on 22.05.2018.
//

#include "FactoryMethod.h"

factoryMethod::MyType::MyType() {}

factoryMethod::MyType::~MyType() {}

std::string factoryMethod::MyType::SayHello() {
    return "hello";
}
