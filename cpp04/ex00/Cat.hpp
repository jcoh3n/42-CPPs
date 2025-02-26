#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    virtual ~Cat();
    Cat(const Cat &copy);
    Cat &operator=(const Cat &cat);
    virtual void makeSound() const;
};

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    virtual ~WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &cat);
    virtual void makeSound() const;
};

#endif