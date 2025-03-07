#include "ScalarConverter.hpp"

ScalarConverter::Type ScalarConverter::determineType(const std::string &input) {
    if (isSpecialCase(input)) return SPECIAL;
    if (isChar(input)) return CHAR;
    if (isInt(input)) return INT;
    if (isFloat(input)) return FLOAT;
    if (isDouble(input)) return DOUBLE;
    return INVALID;
}


void ScalarConverter::convert(const std::string &input) {

    Type type = determineType(input);
    switch (type) {
        case CHAR:
            printConversionChar(input[0]);
            break;
        case INT:
            printConversionInt(std::atoi(input.c_str()));
            break;
        case FLOAT:
            printConversionFloat(static_cast<float>(std::atof(input.c_str())));
            break;
        case DOUBLE:
            printConversionDouble(std::atof(input.c_str()));
            break;
        case SPECIAL:
            handleSpecialCase(input);
            break;
        case INVALID:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}