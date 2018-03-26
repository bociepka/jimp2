//
// Created by Bartek on 20.03.2018.
//

#include "Square.h"
#include <iostream>
#include <cmath>
#include <ostream>
#include "Point.h"

using ::std::cout;
namespace geometry {

    Square::Square() : v1_(0, 0), v2_(0, 0), v3_(0, 0), v4_(0, 0) {
//        cout << "Konstruktor bezparametrowy" << std::endl;
    }

    Square::Square(Point v1, Point v2, Point v3, Point v4) {
//        cout << "Konstruktor parametrowy" << std::endl;
        v1_ = v1;
        v2_ = v2;
        v3_ = v3;
        v4_ = v4;
    }

    Square::~Square() {
//        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << std::endl;
    }

    double Square::Circumference(){
        return 4*distance(this->v2_,this->v1_);//+distance(this->v3_,this->v2_)+distance(this->v4_,this->v3_)+distance(this->v1_,this->v4_);
    }
    double Square::Area(){
        return pow(distance(this->v1_,this->v2_),2);//*distance(this->v2_,this->v3_);
    }


    double distance(const Point &first,const Point &second) {
        return sqrt(pow(abs(second.GetX() - first.GetX()), 2) + pow(abs(second.GetY() - first.GetY()), 2));
    }
}