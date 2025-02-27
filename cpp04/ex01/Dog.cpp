#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &copy) : Animal() {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &dog)
        this->type = dog.type;
    return *this;
}

void Dog::makeSound() const { std::cout << "Woof Woof" << std::endl; }
