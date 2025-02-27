#include "Brain.hpp"
#include "Dog.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &brain) {
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100)
        return "Invalid index";
    return this->ideas[index];
}

void Brain::setIdea(int index, std::string idea) {
    if (index < 0 || index >= 100)
        return;
    this->ideas[index] = idea;
}
