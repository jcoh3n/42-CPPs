#include "iter.hpp"

int main(void)
{
    int tableauInt[5] = {0, 1, 2, 3, 4};
    size_t size = sizeof(tableauInt) / sizeof(tableauInt[0]);

    std::cout << "\nTableau d'entiers:" << std::endl;
    iter(tableauInt, size, printElement<int>);

    std::string tableauString[5] = {"un", "deux", "trois", "quatre", "cinq"};
    size = sizeof(tableauString) / sizeof(tableauString[0]);

    std::cout << "\nTableau de strings:" << std::endl;
    iter(tableauString, size, printElement<std::string>);
    
    std::cout << "\nTableau d'entiers multiplié par 2:" << std::endl;
    iter(tableauInt, size, Multiply<int>(2));
    iter(tableauInt, size, printElement<int>);

    std::cout << "\nIs even or odd:" << std::endl;
    int tableauDouble[5] = {0, 42, 56, 999, 1000};
    size = sizeof(tableauDouble) / sizeof(tableauDouble[0]);
    iter(tableauDouble, size, isEven<int>);

    return 0;
}

