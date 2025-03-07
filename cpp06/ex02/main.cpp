#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    std::cout << "--- Test de la fonction generate() ---" << std::endl;
    
    Base* instance1 = Base::generate();
    Base* instance2 = Base::generate();
    Base* instance3 = Base::generate();
    
    std::cout << "\n--- Test de identify(Base* p) ---" << std::endl;
    
    std::cout << "Type de instance1: ";
    Base::identify(instance1);
    
    std::cout << "Type de instance2: ";
    Base::identify(instance2);
    
    std::cout << "Type de instance3: ";
    Base::identify(instance3);
    
    std::cout << "\n--- Test de identify(Base& p) ---" << std::endl;
    
    std::cout << "Type de instance1: ";
    Base::identify(*instance1);
    
    std::cout << "Type de instance2: ";
    Base::identify(*instance2);
    
    std::cout << "Type de instance3: ";
    Base::identify(*instance3);
    
    // Nettoyage de la mémoire
    delete instance1;
    delete instance2;
    delete instance3;
    
    return 0;
}