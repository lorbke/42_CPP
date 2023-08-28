#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
}



void ScalarConverter::convert(std::string literal) {
	char   c = 0;
	int    i = 0;
	float  f = 0;
	double d = 0;

	std::istringstream(literal) >> i;
	c = i;
	std::istringstream(literal) >> f;
	std::istringstream(literal) >> d;

	std::cout << c << std::endl;
	std::cout << i << std::endl;
	std::cout << f << std::endl;
	std::cout << d << std::endl;
}


// char errors
	// convert first to int, then to char
// non displayable (not in ascii range)
// impossible (no numbers included in str)

// int errors

// float errors
	//
// -inff
// +inff
// nanf

// double errors
// -inf
// +inf
// nan

// overflows should be handled with message