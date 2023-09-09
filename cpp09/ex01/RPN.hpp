#ifndef RPN_HPP_
#define RPN_HPP_

#include <queue>
#include <exception>

class RPN {
	public:
		static int solve(std::queue<char> expression);
	private:
		RPN();
		~RPN();
		RPN(const RPN & obj);
		RPN& operator=(const RPN& obj);
};

class BadExpression : public std::exception {
	const char * what () const throw () {
		return "Error: bad expression";
	}
};


#endif  // RPN_HPP_
