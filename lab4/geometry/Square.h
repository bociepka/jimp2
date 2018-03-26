//
// Created by Bartek on 20.03.2018.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include <cmath>
#include <ostream>
#include "Point.h"
namespace geometry {
    class Square {
    public:
        Square();

        Square(Point v1, Point v2, Point v3, Point v4);

        ~Square();

        double Circumference();
        double Area();

    private:
        Point v1_, v2_, v3_, v4_;
    };

    double distance(const Point &first,const Point &second);
}



#endif //JIMP_EXERCISES_SQUARE_H
