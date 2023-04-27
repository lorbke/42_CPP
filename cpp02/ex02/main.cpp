
#include "Fixed.hpp"
#include <iostream>

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

// @note why is the converted 42.42 = 42.4219?
// has something to do with loss of precision
// https://www.h-schmidt.net/FloatConverter/IEEE754.html

// @todo better understanding of the conversion from float to int

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
