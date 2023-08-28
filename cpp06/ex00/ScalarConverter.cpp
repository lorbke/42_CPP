#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>

#define PREFIX_CHAR   "char:   "
#define PREFIX_INT    "int:    "
#define PREFIX_FLOAT  "float:  "
#define PREFIX_DOUBLE "double: "
#define ERR_INPUT "impossible"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
}

void printScalars(const std::string& literal, const int i, const float f, const double d) {
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
		std::cout << PREFIX_INT    << i << std::endl;
		std::cout << PREFIX_FLOAT  << f;
		if (f == (int)f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << PREFIX_DOUBLE << d;
		if (d == (int)d)
			std::cout << ".0";
		std::cout << std::endl;
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

int strToInt(const std::string& literal) {
	int i = 0;
	std::istringstream(literal) >> i;
	return i;
}

float strToFloat(const std::string& literal) {
	float f = 0;
	std::istringstream(literal) >> f;
	return f;
}

double strToDouble(const std::string& literal) {
	double d = 0;
	std::istringstream(literal) >> d;
	return d;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal == "inf" || literal == "+inf"
		|| literal == "inff" || literal == "+inff")
		printInfpos();
	else if (literal == "-inf" || literal == "-inff")
		printInfneg();
	else if (literal == "nan" || literal == "nanf")
		printNan();
	else {
		// if (!literal.find("."))
		// 	literal.append(std::string(".0"));
		int    i = strToInt(literal);
		float  f = strToFloat(literal);
		double d = strToDouble(literal);
		printScalars(literal, i, f, d);
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