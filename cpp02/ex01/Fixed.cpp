#include "Fixed.hpp"

Fixed::Fixed () : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int value) : value(value << bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float value) : value(roundf(value * (1 << bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;  // Utilise l'opérateur d'affectation
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.value;
    }
    return (*this);
}

Fixed::~Fixed () {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << bits));
}

int Fixed::toInt(void) const
{
    return (this->value >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return (out);
}
