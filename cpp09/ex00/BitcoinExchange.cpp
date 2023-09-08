#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) {
	this->_database = obj._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	this->_database = obj._database;
	return *this;
}

int parse_date(int year, int month, int day) {
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return -1;
	return year * 10000 + month * 100 + day;
}

void BitcoinExchange::database_to_map(const char* filename) {
	std::fstream file(filename);
	std::string line;
	if (!file.is_open())
		throw FileError();
	getline(file, line);
	int year, month, day;
	float price;
	while (std::getline(file, line)) {
		int ret = sscanf(line.c_str(), "%d-%d-%d,%f", &year, &month, &day, &price);
		int date = parse_date(year, month, day);
		if (ret != 4 || date == -1 || price < 0)
			throw BadData(line);
		_database[date] = price;
	}
	file.close();
}

float BitcoinExchange::get_price_at_date(const int date, const float amount) const {
	std::map<int, float>::const_iterator it = _database.lower_bound(date);
	if (it == _database.end())
		return -1;
	float price = it->second * amount;
	return price;
}

std::string BitcoinExchange::evaluate(char* filename) const {
	std::fstream file(filename);
	std::string line;
	if (!file.is_open())
		throw FileError();
	getline(file, line);
	int year, month, day;
	float amount;
	std::stringstream result;
	while (std::getline(file, line)) {
		int ret = sscanf(line.c_str(), "%d-%d-%d | %f", &year, &month, &day, &amount);
		int date = parse_date(year, month, day);
		float price = get_price_at_date(date, amount);
		if (ret != 4)
			result << "Error: bad input syntax => " << line << std::endl;
		else if (date == -1)
			result << "Error: bad date => " << line << std::endl;
		else if (amount < 0)
			result << "Error: not a positive number => " << amount << std::endl;
		else if (amount > 1000)
			result << "Error: amount must not be higher than 1000 => " << amount << std::endl;
		else if (price == -1)
			result << "Error: input date too early" << std::endl;
		else if (price < 0)
			result << "Error: arithmetic error" << std::endl;
		else {
			result << year << "-" << month << "-" << day;
			result <<" => " << amount << " = ";
			result << price;
			result << std::endl;
		}
	}
	file.close();
	return result.str();
}