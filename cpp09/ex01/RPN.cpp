#include "RPN.hpp"
#include <queue>
#include <stack>
#include <cctype>
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN & obj) { *this = obj; }

RPN& RPN::operator=(const RPN& obj) {
	(void)obj;
	return *this;
}

void solve_next(std::stack<int>& buffer, const char op) {
	int left, right;

	if (buffer.empty())
		throw BadExpression();
	right = buffer.top();
	buffer.pop();
	if (buffer.empty())
		throw BadExpression();
	left = buffer.top();
	buffer.pop();

	switch (op) {
		case '+':
			left += right;
			break;
		case '-':
			left -= right;
			break;
		case '*':
			left *= right;
			break;
		case '/':
			if (right == 0)
				throw BadExpression();
			left /= right;
			break;
	}

	buffer.push(left);
}

int RPN::solve(std::queue<char> expression) {
	std::stack<int> buffer;

	while (!expression.empty()) {
		if (isdigit(expression.front())) {
			buffer.push(expression.front() - '0');
			expression.pop();
		}
		else {
			solve_next(buffer, expression.front());
			expression.pop();
		}
	}

	if (buffer.size() != 1)
		throw BadExpression();

	return buffer.top();
}
