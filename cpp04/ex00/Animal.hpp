#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string type);
    ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &animal);
    std::string getType() const;
    void makeSound() const;
};

#endif