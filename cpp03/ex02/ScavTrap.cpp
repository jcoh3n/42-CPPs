#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) { std::cout << "SCAVTRAP default is created" << std::endl; }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) { std::cout << "SCAVTRAP " << name << " is created" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {}

ScavTrap::~ScavTrap() { std::cout << "SCAVTRAP " << this->name << " is destroyed" << std::endl; }

void ScavTrap::attack(const std::string &target)
{
    if (this->HP == 0)
    {
        std::cout << "SCAVTRAP " << this->name << " is dead, it cannot attacks..." << std::endl;
        return;
    }

    if (this->energyPoints < 1)
    {
        std::cout << "SCAVTRAP " << this->name << " can't attack!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "SCAVTAP " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() { std::cout << "SCAVTRAP " << this->name << " have enterred in Gate keeper mode" << std::endl; }
