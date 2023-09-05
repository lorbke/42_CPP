#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#define DATABASE "data.csv"

class FileError : public std::exception {
	public:
		const char *what() const throw() {
			return "file not found";
		}
};

class BadInput: public std::exception {
	public:
		BadInput(const std::string line) {
			_msg = "bad input => " + line;
		}
		const char *what() const throw() {
			return _msg.c_str();
		}
	private:
		std::string _msg;
};

class NotPos: public std::exception {
	public:
		const char *what() const throw() {
			return "not a positive number.";
		}
};

class ArithErr: public std::exception {
	public:
		const char *what() const throw() {
			return "arithmetic error.";
		}
};

void print_map(std::map<int, float, less_equal> &database) {
	for (std::map<int, float>::iterator it = database.begin(); it != database.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int date_to_int(std::string date) {
	int year, month, day;
	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	return year * 10000 + month * 100 + day;
}

std::map<int, float, less_equal> file_to_map(std::string filename) {
	std::map<int, float, less_equal> database;
	std::fstream file(filename.c_str());
	std::string line;
	if (!file.is_open())
		throw FileError();
	getline(file, line);
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1);
		database[date_to_int(date)] = std::atof(price.c_str());
	}
	file.close();
	return database;
}

void print_prices(BitcoinExchange exchange, std::string filename) {
	std::fstream file(filename.c_str());
	if (!file.is_open())
		throw FileError();
	std::string line;

	getline(file, line);
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find('|') - 1);
		std::string amount = line.substr(line.find('|') + 2);
		if (line.find('|') == std::string::npos)
			throw BadInput(line);
		std::cout << date << " " << "=>" << " " << amount << " = ";
		std::cout << exchange.get_price(date_to_int(date), std::atof(amount.c_str()));
		std::cout << std::endl;
	}

	file.close();
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "usage: ./btc [input file]" << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange exchange(file_to_map(DATABASE));

	print_prices(exchange, argv[1]);

	return EXIT_SUCCESS;
}

// basic input parsing in main

// advanced parsing in btc class

// whole database is handled via the class

// class will be instantiable

// 