#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int parse(const std::string& literal) {
	static std::string allowed = "+-0123456789.fnai";
	if (literal.find_first_not_of(allowed) != std::string::npos)
		return EXIT_FAILURE;

	// static std::string sign = "+-";
	// static std::string numbers = "0123456789";
	// size_t first_sign = literal.find_first_of(sign);
	// size_t first_number = literal.find_first_of(numbers);
	// size_t last_number = literal.find_last_of(numbers);
	// size_t dot = literal.find_first_of('.');
	// size_t f = literal.find_first_of('f');
	// if (first_sign != std::string::npos && first_sign != 0)
	// 	return EXIT_FAILURE;
	// else if (literal
	return EXIT_SUCCESS;
}

// @todo handle overflows
// @todo kinda not following the subject since type is not detected
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "usage: ./scalarconverter [value]" << std::endl;
		return EXIT_FAILURE;
	}
	if (parse(argv[1]) == EXIT_FAILURE) {
		std::cout << "bad input, get it together!" << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}