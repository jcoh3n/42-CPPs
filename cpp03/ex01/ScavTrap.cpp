#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}
