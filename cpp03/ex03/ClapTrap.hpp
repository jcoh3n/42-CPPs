#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    int HP;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string name, int attackDamage);
    ClapTrap(std::string name, int HP, int energyPoints, int attackDamage);
    ClapTrap(const ClapTrap &copy);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    int getHP() const;
    std::string getName() const;
    void setDamage(int damage);
};


#endif