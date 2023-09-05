#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <string>

struct less_equal {
	bool operator() (const int lhs, const int rhs) const {
		return lhs > rhs;
	}
};

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::map<int, float, less_equal> database);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		std::map<int, float, less_equal> get_map() const;
		float get_offer(const int date, const float amount) const;
	private:
		std::map<int, float, less_equal> _database;
};

#endif  // BITCOINEXCHANGE_HPP_