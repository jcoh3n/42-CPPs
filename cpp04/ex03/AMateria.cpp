#include "AMateria.hpp"

AMateria::AMateria() : type("default") { std::cout << "AMateria default constructor" << std::endl; }

AMateria::AMateria(std::string const &type) : type(type) { std::cout << "AMateria constructor | Type : " << type << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria destructor" << std::endl; }

AMateria::AMateria(const AMateria &copy) { *this = copy; }

AMateria &AMateria::operator=(const AMateria &amateria)
{
    if (this == &amateria)
        return *this;
    this->type = amateria.type;
    return *this;
}

std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria use | Type : " << type << " | Target : " << target.getName() << std::endl;
}