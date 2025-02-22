#include <iostream>
#include "Point.hpp"

void testPointInsideTriangle(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &testName)
{
    std::cout << testName << " : ";
    if (bsp(a, b, c, p))
        std::cout << "Le point est **DANS** le triangle ✅" << std::endl;
    else
        std::cout << "Le point est **HORS** du triangle ❌" << std::endl;
}

int main()
{
    std::cout << "===== TESTS SUR UN TRIANGLE STANDARD =====\n";
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 8);

    testPointInsideTriangle(a, b, c, Point(5, 4), "Test 1 - Point à l'intérieur");
    testPointInsideTriangle(a, b, c, Point(10, 10), "Test 2 - Point à l'extérieur");
    testPointInsideTriangle(a, b, c, Point(5, 0), "Test 3 - Point sur un bord");
    testPointInsideTriangle(a, b, c, a, "Test 4 - Point au sommet A");
    testPointInsideTriangle(a, b, c, Point(5, 0.0001), "Test 5 - Point proche d'un bord");

    std::cout << "\n===== TESTS SUR UN TRIANGLE RECTANGLE =====\n";
    Point d(0, 0);
    Point e(6, 0);
    Point f(0, 6);

    testPointInsideTriangle(d, e, f, Point(2, 2), "Test 6 - Point à l'intérieur");
    testPointInsideTriangle(d, e, f, Point(6, 6), "Test 7 - Point totalement à l'extérieur");
    testPointInsideTriangle(d, e, f, Point(3, 0), "Test 8 - Point sur l'hypoténuse");
    testPointInsideTriangle(d, e, f, e, "Test 9 - Point sur un sommet");

    std::cout << "\n===== TESTS SUR UN TRIANGLE PLAT =====\n";
    Point g(0, 0);
    Point h(10, 0);
    Point i(5, 0); // Presque colinéaire avec g et h

    testPointInsideTriangle(g, h, i, Point(5, 0), "Test 10 - Point sur le bord d'un triangle plat");
    testPointInsideTriangle(g, h, i, Point(6, 0.00001), "Test 11 - Point légèrement au-dessus du segment");
    testPointInsideTriangle(g, h, i, Point(4, -0.00001), "Test 12 - Point légèrement en dessous du segment");

    std::cout << "\n===== TESTS AVEC POINTS EN ORDRE DIFFÉRENT =====\n";
    testPointInsideTriangle(c, b, a, Point(5, 4), "Test 13 - Point à l'intérieur (ordre inversé)");
    testPointInsideTriangle(c, b, a, Point(10, 10), "Test 14 - Point à l'extérieur (ordre inversé)");

    return 0;
}
