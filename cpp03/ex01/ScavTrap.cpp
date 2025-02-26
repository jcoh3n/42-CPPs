#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {}

ScavTrap::~ScavTrap() {}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}