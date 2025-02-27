#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Animal Tests =====" << std::endl;
    
    Animal genericAnimal;
    Animal genericAnimal2("Marin");
    Dog myDog;
    Cat myCat;
    
    std::cout << "Generic Animal type: " << genericAnimal.getType() << std::endl; // "Animal"
    std::cout << "Generic Animal2 type: " << genericAnimal2.getType() << std::endl; // "Marin"
    std::cout << "My Dog type: " << myDog.getType() << std::endl; // "Dog"
    std::cout << "My Cat type: " << myCat.getType() << std::endl; // "Cat"
    
    std::cout << "Generic Animal sound: ";
    genericAnimal.makeSound(); // "Animal sound"
    
    std::cout << "My Dog sound: ";
    myDog.makeSound(); // "Woof Woof"
    
    std::cout << "My Cat sound: ";
    myCat.makeSound(); // "Meow Meow"
    
    std::cout << "\n===== Wrong Animal Tests =====" << std::endl;
    
    WrongAnimal genericWrongAnimal;
    WrongCat myWrongCat;
    
    std::cout << "Generic WrongAnimal type: " << genericWrongAnimal.getType() << std::endl; // "WrongAnimal"
    std::cout << "My WrongCat type: " << myWrongCat.getType() << std::endl; // "WrongCat"
    
    std::cout << "Generic WrongAnimal sound: ";
    genericWrongAnimal.makeSound(); // "WrongAnimal sound"
    
    std::cout << "My WrongCat sound: ";
    myWrongCat.makeSound(); // "WrongAnimal sound" 
    
    std::cout << "\n===== End of Tests =====" << std::endl;
    
    return 0;
}