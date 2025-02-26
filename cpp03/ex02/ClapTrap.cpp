#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), HP(10), energyPoints(10), attackDamage(0) { std::cout << "ClapTrap " << name << " is created" << std::endl; }

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), energyPoints(10), attackDamage(0) { std::cout << "ClapTrap " << name << " is created" << std::endl; }

ClapTrap::ClapTrap(std::string name, int attackDamage) 
    : name(name), HP(10), energyPoints(10), attackDamage(attackDamage) {
    std::cout << "ClapTrap " << name << " is created with attack damage " << attackDamage << std::endl;
}

ClapTrap::ClapTrap(std::string name, int HP, int energyPoints, int attackDamage) 
    : name(name), HP(HP), energyPoints(energyPoints), attackDamage(attackDamage)
{
    std::cout << "ClapTrap " << name << " is created with HP " << HP << ", energy points " << energyPoints << " and attack damage " << attackDamage << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name), HP(copy.HP), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << this->getName() << " is destroyed" << std::endl; }

void ClapTrap::attack(const std::string &target)
{
    if (this->HP == 0) // Verification si le ClapTrap est mort
    {
        std::cout << "ClapTrap " << this->name << " is dead, it cannot attacks..." << std::endl;
        return;
    }

    if (this->energyPoints < 1) // Verification si le ClapTrap a assez d'energie
    {
        std::cout << "ClapTrap " << this->name << " does not have enough energy points to attack!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HP == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead, it cannot take more damage!" << std::endl;
        return;
    }
    
    if (amount >= this->HP) // Verification si il va mourir apres le coup
    {
        this->HP = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        this->HP -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    }
}




void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HP == 0)
    {
        std::cout << "ClapTrap " << name << " is dead, it cannot be repaired!" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " does not have enough energy points to be repaired!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->HP += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
}


int ClapTrap::getHP() const { return (this->HP); }

std::string ClapTrap::getName() const { return (this->name); }

void ClapTrap::setDamage(int damage) { this->attackDamage = damage; }