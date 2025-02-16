#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string typeName)
{
    this->type = typeName;
}

const std::string& Weapon::getType() const
{
    return this->type;
}

