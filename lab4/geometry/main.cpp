//
// Created by Bartek on 20.03.2018.
//

#include "Point.h"
#include "Square.h"
#include <iostream>

int main(){
    geometry::Point p1(0,0);
    geometry::Point p2(1,0);
    geometry::Point p3(0,1);
    geometry::Point p4(1,1);
    geometry::Square square(p1,p2,p3,p4);
    std::cout << "Obwod"<<square.Circumference();
}