#include "ClapTrap.hpp"

int main() {
    std::cout << "Creating ClapTraps..." << std::endl;
    ClapTrap robo1("Robo1");
    ClapTrap robo2("Robo2");

    std ::cout << "Setting attack damage..." << std::endl;
    robo1.setDamage(3);
    robo2.setDamage(5);
    
    std::cout << "\n=== Battle Begins ===" << std::endl;
    
    // First round
    robo1.attack("Robo2");
    robo2.takeDamage(3);
    std::cout << "Robo2 HP: " << robo2.getHP() << std::endl;
    
    // Repair
    robo2.beRepaired(2);
    std::cout << "Robo2 HP after repair: " << robo2.getHP() << std::endl;
    
    // Second round
    robo2.attack("Robo1");
    robo1.takeDamage(5);
    std::cout << "Robo1 HP: " << robo1.getHP() << std::endl;
    
    robo1.beRepaired(1);
    std::cout << "Robo1 HP after repair: " << robo1.getHP() << std::endl;
    
    // Testing energy depletion
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    // lui enlever toute son energie
    for (int i = 0; i < 8; i++) {
        robo1.attack("Robo2");
    }

    robo1.attack("Robo2"); // plus d'energie
    
    std::cout << "\n=== Testing HP Depletion ===" << std::endl;
    robo2.takeDamage(10); // devrait faire mourir robo2
    robo2.beRepaired(5);  // marche pas car il est mort
    robo2.attack("Robo1"); // marche pas car il est mort
    
    std::cout << "\n=== Battle Ends ===" << std::endl;
    
    return (0);
}