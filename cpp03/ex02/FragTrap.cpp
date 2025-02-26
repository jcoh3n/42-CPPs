#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30) { std::cout << "FRAGTRAP default is created" << std::endl; }

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) { std::cout << "FRAGTRAP " << name << " is created" << std::endl; }

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {}

FragTrap::~FragTrap() { std::cout << "FRAGTRAP " << this->name << " is destroyed" << std::endl; }

void FragTrap::highFivesGuys(void) { std::cout << "FRAGTRAP " << this->name << " is asking for a high five!" << std::endl; }