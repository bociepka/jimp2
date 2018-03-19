//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"



int Factorial(int value) {
    if (IfOutOfRange(value))
        return 0;
    if (value == 1 || value == 0)
        return 1;
    if (value > 0)
        return value * Factorial(value - 1);
    else
        return value * Factorial(value + 1);
}

bool IfOutOfRange(int value) { return value < -12 || value > 12; }
