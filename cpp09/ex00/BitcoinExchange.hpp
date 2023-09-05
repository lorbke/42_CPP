#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <exception>
#include <string>

struct less_equal {
	bool operator() (const int lhs, const int rhs) const {
		return lhs > rhs;
	}
};

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		std::map<int, float, less_equal> get_map() const;
		float get_price_at_date(std::string date) const;
	private:
		std::map<int, float, less_equal> _database;
};

class DatabaseError : public std::exception {
	public:
		const char *what() const throw() {
			return "BitcoinExchange::DatabaseError: database file not found";
		}
};

#endif  // BITCOINEXCHANGE_HPP_