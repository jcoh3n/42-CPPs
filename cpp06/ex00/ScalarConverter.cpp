#include "ScalarConverter.hpp"
#include <cctype> // std::isdigit
#include <sstream> // fonctions de conversion -> int, float, double
#include <iomanip> // std::setprecision
#include <limits> // std::numeric_limits
#include <cstdlib> // std::atoi, std::atof
#include <cmath> // std::isnan, std::isinf

// CAS SPECIAUX
bool ScalarConverter::isSpecialCase(std::string input) {
    return (input == "nan" || input == "inf" || input == "-inf" ||
            input == "nanf" || input == "inff" || input == "-inff");
}

void ScalarConverter::handleSpecialCase(std::string const &input) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (input == "nan" || input == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (input == "inf" || input == "inff") {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    } else if (input == "-inf" || input == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// CHECK TYPE PART
bool ScalarConverter::isChar(std::string input) {
    if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(std::string input) {
    if (input.length() == 1 && !std::isdigit(input[0])) return false;
    for (size_t i = 0; i < input.length(); i++) {
        if (i == 0 && (input[i] == '+' || input[i] == '-')) continue;
        if (!std::isdigit(input[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(std::string input) {
    if (input == "-inff" || input == "+inff" || input == "nanf") return true;

    size_t i = 0;
    if (input[0] == '-' || input[0] == '+') i++;
    
    bool has_decimal = false;
    for (; i < input.length(); i++) {
        if (input[i] == '.') {
            if (has_decimal) return false; // + de 1 '.' dans le nombre -> pas un float
            has_decimal = true;
        } else if (input[i] == 'f') {
            if (i == input.length() - 1 && has_decimal) return true; // 'f' à la fin et point décimal présent
            return false;
        } else if (!std::isdigit(input[i])) return false;
    }
    return false; // Pas de 'f' trouvé
}

bool ScalarConverter::isDouble(std::string input) {
    if (input == "-inf" || input == "+inf" || input == "nan") return true;

    size_t i = 0;
    if (input[0] == '-' || input[0] == '+') i++;
    
    bool has_decimal = false;
    for (; i < input.length(); i++) {
        if (input[i] == '.') {
            if (has_decimal) return false;
            has_decimal = true;
        } else if (!std::isdigit(input[i])) return false;
    }
    return has_decimal;
}

// PRINT PART
void ScalarConverter::printChar(char c) {
    std::cout << "char: ";
    if (std::isprint(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

// Fonctions d'affichage génériques
void ScalarConverter::printConversionChar(char c) {
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::printConversionInt(int i) {
    printChar(static_cast<char>(i));
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::printConversionFloat(float f) {
    printChar(static_cast<char>(f));
    printInt(static_cast<int>(f));
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::printConversionDouble(double d) {
    printChar(static_cast<char>(d));
    printInt(static_cast<int>(d));
    printFloat(static_cast<float>(d));
    printDouble(d);
}
