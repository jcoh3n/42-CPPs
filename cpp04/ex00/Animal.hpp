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
    ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &animal);
    std::string getType() const;
    void makeSound() const;
};

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &animal);
    std::string getType() const;
    void makeSound() const;
};

#endif