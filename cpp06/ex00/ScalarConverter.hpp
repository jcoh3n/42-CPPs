#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>


class ScalarConverter
{
public:
    static void convert(const std::string &input);

private:
    enum Type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        SPECIAL,
        INVALID
    };

    static bool isChar(std::string input);
    static bool isInt(std::string input);
    static bool isFloat(std::string input);
    static bool isDouble(std::string input);
    static bool isSpecialCase(std::string input);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    static void handleSpecialCase(const std::string &input);

    static Type determineType(const std::string &input);
    static void printConversionChar(char c);
    static void printConversionInt(int i);
    static void printConversionFloat(float f);
    static void printConversionDouble(double d);
};

#endif