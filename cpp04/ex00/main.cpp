#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Basic Animal Tests =====" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n===== Wrong Animal Tests =====" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongAnimal->makeSound();
    wrongCat->makeSound(); // should output WrongAnimal sound, not WrongCat
    
    delete wrongAnimal;
    delete wrongCat;
    
    std::cout << "\n===== Direct Animal Tests =====" << std::endl;
    
    // Testing direct objects, not pointers
    Animal directAnimal;
    Dog directDog;
    Cat directCat;
    
    std::cout << directAnimal.getType() << " " << std::endl;
    std::cout << directDog.getType() << " " << std::endl;
    std::cout << directCat.getType() << " " << std::endl;
    
    directAnimal.makeSound();
    directDog.makeSound();
    directCat.makeSound();
    
    std::cout << "\n===== End of Tests =====" << std::endl;
    
    return 0;
}
