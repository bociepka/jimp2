//
// Created by Bartek on 06.03.2018.
//

#include "Array2D.h"
#include <iostream>
using namespace std;
int main(){
    int ** Array = Array2D(3,4);
    FillArray(Array, 3, 4);
    cout<<Array[1][1];
}
