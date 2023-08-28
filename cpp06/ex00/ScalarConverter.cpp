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

void print_scalars(const char c, const int i, const float f, const double d) {
	std::cout << c << std::endl;
	std::cout << i << std::endl;
	std::cout << f << std::endl;
	std::cout << d << std::endl;
}

int str_to_int(const std::string& literal) {
	int i = 0;
	std::istringstream(literal) >> i;
	return i;
}

char int_to_char(const int i) {
	return i;
}

float str_to_float(const std::string& literal) {
	float f = 0;
	std::istringstream(literal) >> f;
	return f;
}

double str_to_double(const std::string& literal) {
	double d = 0;
	std::istringstream(literal) >> d;
	return d;
}

void ScalarConverter::convert(const std::string& literal) {
	int    i = str_to_int(literal);
	char   c = int_to_char(i);
	float  f = str_to_float(literal);
	double d = str_to_double(literal);

	print_scalars(c, i, f, d);
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