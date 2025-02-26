#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Création d'un ClapTrap
    std::cout << "----- Creating ClapTrap -----" << std::endl;
    ClapTrap clap("Clappy");
    std::cout << std::endl;

    // Création d'un ScavTrap
    std::cout << "----- Creating ScavTrap -----" << std::endl;
    ScavTrap scav("Scavy");
    std::cout << std::endl;

    // Test des fonctions de ClapTrap
    std::cout << "----- Testing ClapTrap functions -----" << std::endl;
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << std::endl;

    // Test des fonctions de ScavTrap
    std::cout << "----- Testing ScavTrap functions -----" << std::endl;
    scav.attack("Target2");
    scav.takeDamage(15);
    scav.beRepaired(10);
    scav.guardGate();  // Fonction spécifique à ScavTrap
    std::cout << std::endl;

    // Destruction des objets
    std::cout << "----- Destroying objects -----" << std::endl;
    return 0;
}