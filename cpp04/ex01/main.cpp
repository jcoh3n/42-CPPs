#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Test 1 : Création d'un Animal, d'un Dog et d'un Cat
    std::cout << "=== Test 1 : Création d'un Animal, d'un Dog et d'un Cat ===" << std::endl;
    const Animal* meta = new Animal();  // Instanciation directe d'un Animal, comme montré dans les consignes
    const Animal* dog1 = new Dog();
    const Animal* cat1 = new Cat();
    std::cout << std::endl;

    // Test 2 : Polymorphisme avec Animal
    std::cout << "=== Test 2 : Polymorphisme avec Animal ===" << std::endl;
    std::cout << "Type de dog1: " << dog1->getType() << std::endl;
    std::cout << "Type de cat1: " << cat1->getType() << std::endl;
    cat1->makeSound();  // Doit afficher "Meow!"
    dog1->makeSound();  // Doit afficher "Woof!"
    meta->makeSound();  // Doit afficher le son d'Animal (selon votre implémentation)
    std::cout << std::endl;

    // Test 3 : Libération de la mémoire
    std::cout << "=== Test 3 : Libération de la mémoire ===" << std::endl;
    delete meta;
    delete dog1;
    delete cat1;
    std::cout << std::endl;

    // Test 4 : Copie d'un Dog et d'un Cat (comme dans votre code)
    std::cout << "=== Test 4 : Copie d'un Dog et d'un Cat ===" << std::endl;
    Dog dog2;
    Cat cat2;
    {
        Dog tmpDog;
        Cat tmpCat;
        dog2 = tmpDog;  // Test d'assignation
        cat2 = tmpCat;  // Test d'assignation
    }
    dog2.makeSound();  // Doit afficher "Woof!"
    cat2.makeSound();  // Doit afficher "Meow!"
    std::cout << std::endl;
    
    return 0;
}