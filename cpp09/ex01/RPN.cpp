#include "RPN.hpp"
#include <queue>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & obj) { *this = obj; }

RPN& RPN::operator=(const RPN& obj) {
	(void)obj;
	return *this;
}

int RPN::solve(std::queue<char> expression) {
	int left = expression.front() - '0';
	expression.pop();
	int right = 0;

	while (!expression.empty()) {
		right = expression.front() - '0';
		expression.pop();
		if (expression.empty())
			throw BadExpression();
		if (expression.front() == '+')
			left += right;
		else if (expression.front() == '-')
			left -= right;
		else if (expression.front() == '*')
			left *= right;
		else if (expression.front() == '/') {
			if (right == 0)
				throw BadExpression();
			left /= right;
		}
		else
			throw BadExpression();
		expression.pop();
	}

	return left;
}