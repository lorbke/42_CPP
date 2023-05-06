/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:31:13 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 22:22:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ));
	Fixed const c( Fixed( 2 ));

	std::cout << "mutation tests:" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << "arithmetic tests:" << std::endl;
	std::cout << b << std::endl;;
	std::cout << c << std::endl;
	std::cout << (b / c) << std::endl;
	std::cout << (b * c) << std::endl;
	std::cout << (b - c) << std::endl;
	std::cout << (b + c) << std::endl;
	std::cout << std::endl;

	std::cout << "comparison tests:" << std::endl;
	std::cout << (c < b) << std::endl;
	std::cout << (c > b) << std::endl;
	std::cout << (c <= b) << std::endl;
	std::cout << (c >= b) << std::endl;
	std::cout << (c == b) << std::endl;
	std::cout << (c != b) << std::endl;
	std::cout << std::endl;

	std::cout << "min max tests:" << std::endl;
	std::cout << Fixed::max( c, b ) << std::endl;
	std::cout << Fixed::min( c, b ) << std::endl;
	std::cout << std::endl;
	return 0;
}
