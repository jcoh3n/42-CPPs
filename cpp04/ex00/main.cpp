#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Animal Tests (Polymorphic Behavior) =====" << std::endl;
    
    // Polymorphisme avec Animal, Dog et Cat
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    std::cout << "Animal1 (Dog) sound: ";
    animal1->makeSound(); // "Woof Woof"
    
    std::cout << "Animal2 (Cat) sound: ";
    animal2->makeSound(); // "Meow Meow"
    
    delete animal1;
    delete animal2;
    
    std::cout << "\n===== Wrong Animal Tests (Non-Polymorphic Behavior) =====" << std::endl;
    
    // Non-polymorphisme avec WrongAnimal et WrongCat
    WrongAnimal* wrongAnimal = new WrongCat();
    
    std::cout << "WrongAnimal (WrongCat) sound: ";
    wrongAnimal->makeSound(); // "WrongAnimal sound" (pas "WrongCat sound")
    
    delete wrongAnimal;
    
    std::cout << "\n===== End of Tests =====" << std::endl;
    
    return 0;
}
