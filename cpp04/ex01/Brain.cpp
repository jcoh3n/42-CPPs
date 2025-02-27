#include "Brain.hpp"
#include "Dog.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}