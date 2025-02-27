#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Test 1 : Création d'un Dog et d'un Cat
    std::cout << "=== Test 1 : Création d'un Dog et d'un Cat ===" << std::endl;
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();
    std::cout << std::endl;

    // Test 2 : Polymorphisme avec Animal
    std::cout << "=== Test 2 : Polymorphisme avec Animal ===" << std::endl;
    Animal* animals[2];
    animals[0] = dog1;
    animals[1] = cat1;

    for (int i = 0; i < 2; ++i) {
        std::cout << "Type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();  // Doit afficher "Woof!" pour Dog et "Meow!" pour Cat
    }
    std::cout << std::endl;

    // Test 3 : Copie d'un Dog et d'un Cat
    std::cout << "=== Test 3 : Copie d'un Dog et d'un Cat ===" << std::endl;
    Dog dog2(*dog1);  // Copie profonde de dog1
    Cat cat2(*cat1);  // Copie profonde de cat1

    std::cout << "Type de dog2: " << dog2.getType() << std::endl;
    dog2.makeSound();  // Doit afficher "Woof!"
    std::cout << "Type de cat2: " << cat2.getType() << std::endl;
    cat2.makeSound();  // Doit afficher "Meow!"
    std::cout << std::endl;

    // Test 4 : Assignation d'un Dog et d'un Cat
    std::cout << "=== Test 4 : Assignation d'un Dog et d'un Cat ===" << std::endl;
    Dog dog3;
    dog3 = *dog1;  // Assignation profonde de dog1 à dog3

    Cat cat3;
    cat3 = *cat1;  // Assignation profonde de cat1 à cat3

    std::cout << "Type de dog3: " << dog3.getType() << std::endl;
    dog3.makeSound();  // Doit afficher "Woof!"
    std::cout << "Type de cat3: " << cat3.getType() << std::endl;
    cat3.makeSound();  // Doit afficher "Meow!"
    std::cout << std::endl;

    // Test 5 : Destruction des objets
    std::cout << "=== Test 5 : Destruction des objets ===" << std::endl;
    delete dog1;  // Doit appeler le destructeur de Dog et libérer le Brain
    delete cat1;  // Doit appeler le destructeur de Cat et libérer le Brain
    std::cout << std::endl;

    // Test 6 : Vérification des copies profondes
    std::cout << "=== Test 6 : Vérification des copies profondes ===" << std::endl;
    std::cout << "Type de dog2: " << dog2.getType() << std::endl;
    dog2.makeSound();  // Doit toujours fonctionner car copie profonde
    std::cout << "Type de cat2: " << cat2.getType() << std::endl;
    cat2.makeSound();  // Doit toujours fonctionner car copie profonde
    std::cout << std::endl;

    return 0;
}