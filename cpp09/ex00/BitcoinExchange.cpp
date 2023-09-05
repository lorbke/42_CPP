#include "BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::map<int, float, less_equal> database) : _database(database) {
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {
	this->_database = obj._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	this->_database = obj._database;
	return *this;
}

std::map<int, float, less_equal> BitcoinExchange::get_map() const {
	return _database;
}

float BitcoinExchange::get_offer(const int date, const float amount) const {
	std::map<int, float>::const_iterator it = _database.lower_bound(date);
	float price = it->second * amount;
	return price;
}