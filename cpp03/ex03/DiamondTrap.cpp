#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap("default_scav_name"), FragTrap("default_frag_name"), name("default_diamond_name")
{
    std::cout << "DIAMONDTRAP " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), name(name)
{
    std::cout << "DIAMONDTRAP " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name) {}

DiamondTrap::~DiamondTrap() { std::cout << "DIAMONDTRAP " << name << " is destroyed" << std::endl; }

void DiamondTrap::whoAmI() { std::cout << "DIAMONDTRAP " << name << " is also known as ClapTrap " << ClapTrap::getName() << std::endl; }