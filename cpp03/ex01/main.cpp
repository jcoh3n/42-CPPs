#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Création d'un ClapTrap
    std::cout << "----- Creating ClapTrap -----" << std::endl;
    ClapTrap clap("MAX");
    std::cout << std::endl;

    // Création d'un ScavTrap
    std::cout << "----- Creating ScavTrap -----" << std::endl;
    ScavTrap scav("JOE");
    std::cout << std::endl;

    std::cout << "----- Testing ClapTrap functions -----" << std::endl;
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << std::endl;

    std::cout << "----- Testing ScavTrap functions -----" << std::endl;
    scav.attack("Target2");
    scav.takeDamage(15);
    scav.beRepaired(10);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "----- Destroying objects -----" << std::endl;
    return 0;
}