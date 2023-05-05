
#include "Fixed.hpp"
#include <cmath> // roundf()
#include <iostream>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(Fixed const& original)
{
	this->_value = original._value;
}

Fixed::Fixed(int const raw)
{
	this->_value = raw << _fractionalBits;
}

Fixed::Fixed(float const raw)
{
	this->_value = roundf(raw * (1 << _fractionalBits));
}

Fixed&	Fixed::operator=(Fixed const& original)
{
	this->_value = original._value;
	return (*this);
}

bool	Fixed::operator>(Fixed const& other)
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(Fixed const& other)
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(Fixed const& other)
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(Fixed const& other)
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(Fixed const& other)
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(Fixed const& other)
{
	return (this->_value != other._value);
}

Fixed&	Fixed::operator+(Fixed const& addend)
{
	this->_value += addend._value;
	return (*this);
}

Fixed&	Fixed::operator-(Fixed const& subtrahend)
{
	this->_value -= subtrahend._value;
	return (*this);
}

Fixed&	Fixed::operator*(Fixed const& multiplier)
{
	this->_value = this->_value * multiplier.toFloat();
	return (*this);
}

Fixed&	Fixed::operator/(Fixed const& divisor)
{
	this->_value = this->_value / divisor.toFloat();
	return (*this);
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

// @note parameter is a dummy to differentiate between prefix and postfix
Fixed	Fixed::operator++(int postfix __attribute__ ((unused)))
{
	Fixed	temp = *this;

	this->_value++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int postfix __attribute__ ((unused)))
{
	Fixed	temp = *this;

	this->_value--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if ((Fixed&)a < b)
		return (Fixed&)(a);
	return (Fixed&)(b);
}

Fixed&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if ((Fixed&)a > b)
		return (Fixed&)(a);
	return (Fixed&)(b);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
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

std::ostream&	operator<<(std::ostream& out, Fixed const& fixed)
{
	out << fixed.toFloat();
	return (out);
}
