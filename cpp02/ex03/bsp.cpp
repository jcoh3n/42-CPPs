#include "Point.hpp"
#include "Fixed.hpp"

float absolute(float value) { return (value < 0 ? -value : value); }

float calculateArea(const Point &a, const Point &b, const Point &c)
{
    return (absolute((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = calculateArea(a, b, c);

    float areaABP = calculateArea(point, a, b);
    float areaBCP = calculateArea(point, b, c);
    float areaCAP = calculateArea(point, c, a);

    float sommeAreas = areaABP + areaBCP + areaCAP;

    float epsilon = 0.0001;
    return (absolute(sommeAreas - areaABC) < epsilon);
}
