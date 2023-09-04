#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>

void print_map(std::map<int, float, less_equal> &database) {
	for (std::map<int, float>::iterator it = database.begin(); it != database.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int main(void) {
	BitcoinExchange exchange;

	std::cout << exchange.get_price_at_date("2022-03-25") << std::endl;

	return 0;
}

// basic input parsing in main

// advanced parsing in btc class

// whole database is handled via the class

// class will be instantiable

// 