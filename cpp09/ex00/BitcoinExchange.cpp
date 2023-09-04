#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & obj) { *this = obj; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
  (void)obj;
  return *this;
}
