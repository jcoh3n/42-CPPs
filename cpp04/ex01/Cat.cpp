#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &cat)
        this->type = cat.type;
    return *this;
}

void Cat::makeSound() const { std::cout << "Meow Meow" << std::endl; }

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
