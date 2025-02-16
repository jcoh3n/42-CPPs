#include <iostream>
#include <string>


int main() {
    std::string brain_message = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain_message;
    std::string &stringREF = brain_message;

    std::cout << "Address of string: " << &brain_message << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "\nMESSAGE: " << brain_message << std::endl;
    std::cout << "StringPTR: " << *stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;

    return 0;
}
