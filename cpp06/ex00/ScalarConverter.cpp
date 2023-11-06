#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

#define BLUE "\033[0;34m"
#define RESET "\033[0m"

#define PREFIX_CHAR   "char:   "
#define PREFIX_INT    "int:    "
#define PREFIX_FLOAT  "float:  "
#define PREFIX_DOUBLE "double: "
#define ERR_INPUT "impossible"
#define ERR_ARITH "arithmetic exception"

struct Data {
	char   c;
	int    i;
	float  f;
	double d;
};

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
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

void printScalars(Data& data, const std::string& literal) {
	static std::string numbers = "0123456789";
	long double arith_check = 0;
	std::istringstream(literal) >> arith_check;

	if (data.i < 32 || data.i > 127)
		std::cout << PREFIX_CHAR   << "Non displayable" << std::endl;
	else
		std::cout << PREFIX_CHAR   << "'" << data.c << "'" << std::endl;
	if (literal.find_first_of(numbers) == std::string::npos) {
		std::cout << PREFIX_INT    << ERR_INPUT << std::endl;
		std::cout << PREFIX_FLOAT  << ERR_INPUT << std::endl;
		std::cout << PREFIX_DOUBLE << ERR_INPUT << std::endl;
	}
	else {
		if (arith_check > std::numeric_limits<int>::max() || arith_check < -std::numeric_limits<int>::max())
			std::cout << PREFIX_INT << ERR_ARITH << std::endl;
		else
			std::cout << PREFIX_INT << data.i << std::endl;
		if (arith_check > std::numeric_limits<float>::max() || arith_check < -std::numeric_limits<float>::max())
			std::cout << PREFIX_FLOAT << ERR_ARITH << std::endl;
		else {
			std::cout << PREFIX_FLOAT << data.f;
			if (data.f == (int)data.d)
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		if (arith_check > std::numeric_limits<double>::max() || arith_check < -std::numeric_limits<double>::max())
			std::cout << PREFIX_DOUBLE << ERR_ARITH << std::endl;
		else {
			std::cout << PREFIX_DOUBLE << data.d;
			if (data.d == (int)data.d)
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
}

Type getType(std::string& literal) {
	std::istringstream stream_c(literal);
	std::istringstream stream_i(literal);
	std::istringstream stream_d(literal);
	int    i;
	char   c;
	double d;
	if (stream_c >> c && stream_c.eof())
		return CHAR;
	if (literal.find('f') != std::string::npos
		&& literal.find('f') == literal.size() - 1) {
		literal.erase(literal.find('f'));
		std::istringstream stream_f(literal);
		if (stream_f >> d && stream_f.eof())
			return FLOAT;
	}
	if (stream_d >> d && stream_d.eof())
		return DOUBLE;
	if (stream_i >> i && stream_i.eof()) {
		return INT;
	}
	return ERROR;
}

void explicitConversion(Data& data, std::string literal, Type type) {
	std::istringstream stream(literal);
	switch(type) {
		case CHAR:
			stream >> data.c;
			data.i = static_cast<int>(data.c);
			data.f = static_cast<float>(data.c);
			data.d = static_cast<double>(data.c);
			break;
		case INT:
			stream >> data.i;
			data.c = static_cast<char>(data.i);
			data.f = static_cast<float>(data.i);
			data.d = static_cast<double>(data.i);
			break;
		case FLOAT:
			stream >> data.f;
			data.c = static_cast<char>(data.f);
			data.i = static_cast<int>(data.f);
			data.d = static_cast<double>(data.f);
			break;
		case DOUBLE:
			stream >> data.d;
			data.c = static_cast<char>(data.d);
			data.i = static_cast<int>(data.d);
			data.f = static_cast<float>(data.d);
			break;
		case ERROR:
			break;
	}
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
		Type type = getType(literal);
		if (type == ERROR) {
			std::cout << "Error: no possible type conversion" << std::endl;
			return;
		}
		#ifdef DEBUG
			std::cout << BLUE"type: "RESET << type << std::endl;
		#endif
		Data data;
		explicitConversion(data, literal, type);
		printScalars(data, literal);
	}
}