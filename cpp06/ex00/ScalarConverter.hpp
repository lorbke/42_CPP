#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter & obj);
		ScalarConverter& operator=(const ScalarConverter& obj);

	public:
		static void convert(const std::string& literal);
};

#endif  // SCALARCONVERTER_HPP_
