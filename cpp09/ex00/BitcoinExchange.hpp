#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    void loadDatabase(const std::string& databaseFile);
    void processInput(const std::string& inputFile);

private:
    std::map<std::string, float> _prices;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(float value) const;
    void calculateAndDisplay(const std::string& date, float value) const;
};

#endif