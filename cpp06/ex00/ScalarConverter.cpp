#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

#define PREFIX_CHAR   "char:   "
#define PREFIX_INT    "int:    "
#define PREFIX_FLOAT  "float:  "
#define PREFIX_DOUBLE "double: "
#define ERR_INPUT "impossible"
#define ERR_ARITH "arithmetic exception"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
}

void printScalars(const std::string& literal, const long double arith_check, const int i, const float f, const double d) {
	static std::string numbers = "0123456789";

	if (i < 32 || i > 127)
		std::cout << PREFIX_CHAR   << "Non displayable" << std::endl;
	else
		std::cout << PREFIX_CHAR   << "'" << static_cast<char>(i) << "'" << std::endl;
	if (literal.find_first_of(numbers) == std::string::npos) {
		std::cout << PREFIX_INT    << ERR_INPUT << std::endl;
		std::cout << PREFIX_FLOAT  << ERR_INPUT << std::endl;
		std::cout << PREFIX_DOUBLE << ERR_INPUT << std::endl;
	}
	else {
		if (arith_check > std::numeric_limits<int>::max() || arith_check < std::numeric_limits<int>::lowest())
			std::cout << PREFIX_INT << ERR_ARITH << std::endl;
		else
			std::cout << PREFIX_INT << i << std::endl;
		if (arith_check > std::numeric_limits<float>::max() || arith_check < std::numeric_limits<float>::lowest())
			std::cout << PREFIX_FLOAT << ERR_ARITH << std::endl;
		else {
			std::cout << PREFIX_FLOAT << f;
			if (f == (int)f)
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		if (arith_check > std::numeric_limits<double>::max() || arith_check < std::numeric_limits<double>::lowest())
			std::cout << PREFIX_DOUBLE << ERR_ARITH << std::endl;
		else {
			std::cout << PREFIX_DOUBLE << d;
			if (d == (int)d)
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
}

void printInfpos() {
	std::cout << PREFIX_CHAR   << ERR_INPUT << std::endl;
	std::cout << PREFIX_INT    << ERR_INPUT << std::endl;
	std::cout << PREFIX_FLOAT  << "+inff" << std::endl;
	std::cout << PREFIX_DOUBLE << "+inf" << std::endl;
}

void printInfneg() {
	std::cout << PREFIX_CHAR   << ERR_INPUT << std::endl;
	std::cout << PREFIX_INT    << ERR_INPUT << std::endl;
	std::cout << PREFIX_FLOAT  << "-inff" << std::endl;
	std::cout << PREFIX_DOUBLE << "-inf" << std::endl;
}

void printNan() {
	std::cout << PREFIX_CHAR   << ERR_INPUT << std::endl;
	std::cout << PREFIX_INT    << ERR_INPUT << std::endl;
	std::cout << PREFIX_FLOAT  << "nanf" << std::endl;
	std::cout << PREFIX_DOUBLE << "nan" << std::endl;
}

void ScalarConverter::convert(std::string literal) {
	if (literal == "inf" || literal == "+inf"
		|| literal == "inff" || literal == "+inff")
		printInfpos();
	else if (literal == "-inf" || literal == "-inff")
		printInfneg();
	else if (literal == "nan" || literal == "nanf")
		printNan();
	else {
		if (literal.find('f') != std::string::npos)
			literal.erase(literal.find('f'));
		int    i = 0;
		float  f = 0;
		double d = 0;
		long double arith_check = 0;
		std::istringstream(literal) >> arith_check;
		std::istringstream(literal) >> i;
		std::istringstream(literal) >> f;
		std::istringstream(literal) >> d;
		printScalars(literal, arith_check, i, f, d);
	}
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