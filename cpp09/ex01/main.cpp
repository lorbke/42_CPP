#include "RPN.hpp"
#include <queue>
#include <iostream>

std::queue<char> str_to_queue(const std::string& str) {
	std::queue<char> queue;
	std::string tmp;

	for (int i = 0; str[i]; i++) {
		if (str[i] != ' ')
			queue.push(str[i]);
	}

	return queue;
}

std::queue<char> parse_str_expr(const std::string& str) {
	static std::string allowed = "0123456789+-*/";
	for (int i = 0; str[i]; i++) {
		if (i % 2 == 0 && allowed.find(str[i]) == std::string::npos) {
			std::cerr << "Error: bad expression" << std::endl;
			exit(1);
		}
		else if (i % 2 == 1 && str[i] != ' ') {
			std::cerr << "Error: bad expression" << std::endl;
			exit(1);
		}
	}
	return str_to_queue(str);
}

void print_queue(std::queue<char> queue) {
	std::cout << "stack: ";
	while (!queue.empty()) {
		std::cout << queue.front() << " ";
		queue.pop();
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./a.out \"<expression>\"" << std::endl;
		return 1;
	}

	std::queue<char> expression = parse_str_expr(argv[1]);

	print_queue(expression);

	try {
		std::cout << RPN::solve(expression) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}