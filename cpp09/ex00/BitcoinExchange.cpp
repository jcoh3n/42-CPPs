#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    loadDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& databaseFile)
{
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) throw std::runtime_error("Error: could not open database file.");

    std::string line;
    while (std::getline(file, line))
    {
        size_t virgule = line.find(',');
        if (virgule != std::string::npos)
        {
            std::string date = line.substr(0, virgule); // chope la date avant la virgule
            std::string priceStr = line.substr(virgule + 1); // chope le prix après la virgule
            float price;
            std::istringstream(priceStr) >> price; // convertie le string en float
            _prices[date] = price;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char sep1, sep2;
    std::istringstream(date) >> year >> sep1 >> month >> sep2 >> day;

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
    if (value <= 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (value > 1000000)
    {
        std::cerr << "Error: too large number." << std::endl;
        return false;
    }
    return true;
}


void BitcoinExchange::calculateAndDisplay(const std::string& date, float value) const
{
    // lower_bound return le 1er element qui est >= date
    std::map<std::string, float>::const_iterator it = _prices.lower_bound(date);

    // si on ne toruve pas la date
    if (it == _prices.begin() && it->first != date) {
        std::cerr << "Error: no data available for date " << date << std::endl;
        return;
    }

    // on trouve la date la plus proche
    if (it->first != date && it != _prices.begin())
        --it;

    float exchangeRate = it->second;
    float result = value * exchangeRate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    // passe la première ligne (en-tête)
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos - 1);
        std::string valueStr = line.substr(pipePos + 2);
        float value;

        if (valueStr.find('e') != std::string::npos || valueStr.find('E') != std::string::npos) {
            std::cerr << "Error: invalid value format => " << valueStr << std::endl;
            continue;
        }

        // Vérification que la valeur est un nombre valide
        std::istringstream iss(valueStr);
        iss >> value;
        if (iss.fail() || !iss.eof()) {
            std::cerr << "Error: invalid value format => " << valueStr << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!isValidValue(value)) continue;

        calculateAndDisplay(date, value);
    }
}