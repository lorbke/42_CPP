
#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	this->_value = original._value;
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
