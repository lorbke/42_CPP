#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <cstdio>
#include <iostream>

#define DEFAULT_DATABASE "data.csv"

void file_to_map(std::map<int, float, less_equal>& database, std::string filename);
int date_to_int(std::string date);

BitcoinExchange::BitcoinExchange() {
	file_to_map(_database, DEFAULT_DATABASE);
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	file_to_map(_database, filename);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) { *this = obj; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	(void)obj;
	return *this;
}

std::map<int, float, less_equal> BitcoinExchange::get_map() const {
	return _database;
}

float BitcoinExchange::get_price_at_date(std::string date) const {
	std::map<int, float>::const_iterator it = _database.lower_bound(date_to_int(date));
	float price = it->second;
	return price;
}

int date_to_int(std::string date) {
	int year, month, day;
	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	return year * 10000 + month * 100 + day;
}

void file_to_map(std::map<int, float, less_equal>& database, std::string filename) {
	std::fstream file(filename);
	std::string line;
	if (!file.is_open())
		throw DatabaseError();
	getline(file, line);
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1);
		database[date_to_int(date)] = std::stof(price);
	}
}