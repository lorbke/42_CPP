#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <map>

#define DATABASE "data.csv"

// class BadInput: public std::exception {
// 	public:
// 		BadInput(const std::string line) {
// 			_msg = "bad input => " + line;
// 		}
// 		const char *what() const throw() {
// 			return _msg.c_str();
// 		}
// 	private:
// 		std::string _msg;
// };

// class NotPos: public std::exception {
// 	public:
// 		const char *what() const throw() {
// 			return "not a positive number.";
// 		}
// };

// class ArithErr: public std::exception {
// 	public:
// 		const char *what() const throw() {
// 			return "arithmetic error.";
// 		}
// };

void print_map(std::map<int, float, less_equal> &database) {
	for (std::map<int, float>::iterator it = database.begin(); it != database.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "usage: ./btc [input file]" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	try {
		exchange.database_to_map(DATABASE);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	try {
		std::cout << exchange.evaluate(argv[1]) << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}