#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &copy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &cat)
        this->type = cat.type;
    return *this;
}

void WrongCat::makeSound() const { std::cout << "WrongCat sound" << std::endl; }