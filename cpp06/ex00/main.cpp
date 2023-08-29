#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int parse(const std::string& literal) {
	static std::string allowed = "+-0123456789.fnai";
	if (literal.find_first_not_of(allowed) != std::string::npos)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

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