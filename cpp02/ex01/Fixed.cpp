
#include "Fixed.hpp"
#include <cmath> // roundf()
#include <iostream>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	this->_value = original._value;
}

Fixed::Fixed(const int raw)
{
	this->_value = raw << _fractionalBits;
}

Fixed::Fixed(const float raw)
{
	this->_value = roundf(raw * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& original)
{
	this->_value = original._value;
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
