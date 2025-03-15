#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

int evaluateRPN(const std::string& expression);

bool isOperator(const std::string& token);
int makeOperation(const std::string& op, int value1, int value2);
bool isNumber(const std::string& token);
void handleOperator(const std::string& token, std::stack<int>& stack);
void handleNumber(const std::string& token, std::stack<int>& stack);
void validateStack(const std::stack<int>& stack);

#endif