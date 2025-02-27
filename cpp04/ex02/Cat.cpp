#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl; 
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &cat) {
        Animal::operator=(cat);
        delete this->brain;
        this->brain = new Brain(*cat.brain);
    }
    return *this;
}

void Cat::makeSound() const { std::cout << "Meow Meow" << std::endl; }

