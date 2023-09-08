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
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		std::string evaluate(char* filename) const;
		void database_to_map(const char* filename);
	private:
		float get_price_at_date(const int date, const float amount) const;
		std::map<int, float, less_equal> _database;
};

class FileError : public std::exception {
	public:
		const char *what() const throw() {
			return "Error: could not open file";
		}
};

class BadData : public std::exception {
public:
	BadData(const std::string& location) : _location("Error: database error => " + location) {}
	virtual const char* what() const throw() {
		return _location.c_str();
	}
	~BadData() throw() {}

private:
    std::string _location;
};


#endif  // BITCOINEXCHANGE_HPP_