#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <string>
#include <iostream>
#include <cstdlib>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter & obj);
		ScalarConverter& operator=(const ScalarConverter& obj);

	public:
		static void convert(const char* literal) {
			int i = std::atoi(literal);
			char c = dynamic_cast<char>(i);
			float f = std::atof(literal);
			double d = f;

			std::cout << c << std::endl;
			std::cout << i << std::endl;
			std::cout << f << std::endl;
			std::cout << d << std::endl;
		};
};

#endif  // SCALARCONVERTER_HPP_
