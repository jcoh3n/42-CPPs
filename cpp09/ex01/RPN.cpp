#include "RPN.hpp"



bool isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const std::string& token)
{
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]) && token[i] != '-')
            return false;
    }
    return true;
}

int makeOperation(const std::string& token, int value1, int value2)
{
    if (token == "+")
        return value1 + value2;
    else if (token == "-")
        return value1 - value2;
    else if (token == "*")
        return value1 * value2;
    else if (token == "/")
    {
        if (value2 == 0)
        {
            std::cerr << "Error: division by zero." << std::endl;
            exit(1);
        }
        return value1 / value2;
    }
    return 0;
}


void handleOperator(const std::string& token, std::stack<int>& stack)
{
    if (stack.size() < 2)
    {
        std::cerr << "Error: not enough operands for operation." << std::endl;
        exit(1);
    }

    int value2 = stack.top();
    stack.pop();
    int value1 = stack.top();
    stack.pop();

    int result = makeOperation(token, value1, value2);
    stack.push(result);
}

void handleNumber(const std::string& token, std::stack<int>& stack)
{
    int number;
    std::istringstream(token) >> number;
    stack.push(number);
}

void validateStack(const std::stack<int>& stack)
{
    if (stack.size() != 1)
    {
        std::cerr << "Error: invalid expression." << std::endl;
        exit(1);
    }
}

int evaluateRPN(const std::string& expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
            handleOperator(token, stack);
        else if (isNumber(token))
            handleNumber(token, stack);
        else
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }

    validateStack(stack);
    return stack.top();
}
