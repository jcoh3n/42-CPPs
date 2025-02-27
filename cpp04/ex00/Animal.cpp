#include "Animal.hpp"

Animal::Animal() : type("Animal") { std::cout << "Animal constructor called" << std::endl; }

Animal::Animal(std::string type) : type(type) { std::cout << "Animal " << type << " constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string Animal::getType() const { return this->type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }

WrongAnimal::WrongAnimal() : type("WrongAnimal") { std::cout << "WrongAnimal constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }