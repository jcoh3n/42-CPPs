#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}


void HumanB::attack()
{
    if (this->weapon == nullptr)
        std::cout << this->name << " has no weapon but still attacks with their bare hands!!" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    std::cout << this->name << " has equipped with a " << this->weapon->getType() << "!" << std::endl;
}
