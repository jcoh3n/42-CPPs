#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <stdbool.h>
#include "Fixed.hpp"

class Point 
{
private:
    float x;
    float y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &copy);
    ~Point();
    Point &operator=(const Point &other);
    float getX() const;
    float getY() const;
};

float absolute(float value);
float calculateArea(const Point &a, const Point &b, const Point &c);
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif