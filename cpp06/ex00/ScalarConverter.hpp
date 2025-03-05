#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
public:
    static void convert(const std::string &input);

private:
    static bool isChar(std::string input);
    static bool isInt(std::string input);
    static bool isFloat(std::string input);
    static bool isDouble(std::string input);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);
};

#endif // SCALARCONVERTER_HPP