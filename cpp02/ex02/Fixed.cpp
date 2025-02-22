#include "Fixed.hpp"

Fixed::Fixed () : value(0) {}

Fixed::Fixed (const int value) : value(value << bits) {}

Fixed::Fixed (const float value) : value(roundf(value * (1 << bits))) {}

Fixed::Fixed (const Fixed &copy) { *this = copy; }

Fixed::~Fixed () {}

int Fixed::getRawBits (void) const { return (this->value); }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat(void) const { return ((float)this->value / (1 << bits)); }

int Fixed::toInt(void) const { return (this->value >> bits); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return (out);
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->value = other.value;
    }
    return (*this);
}

// Operateurs Arithmetiques
Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

// Operateurs de comparaison 
bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}

// Operateur d'incrementation et de decrementation
Fixed &Fixed::operator++()
{
    ++this->value;
    return (*this);
}

Fixed &Fixed::operator--()
{
    --this->value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}
