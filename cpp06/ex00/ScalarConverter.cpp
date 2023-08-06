#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter & obj) { *this = obj; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return *this;
}
