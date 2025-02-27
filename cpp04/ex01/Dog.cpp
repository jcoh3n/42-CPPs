#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &Dog) {
        Animal::operator=(Dog);
        delete this->brain;
        this->brain = new Brain(*Dog.brain);
    }
    return *this;
}

void Dog::makeSound() const { std::cout << "Woof Woof" << std::endl; }
