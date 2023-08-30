#include "Span.hpp"
#include <exception>
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>

#define RED "\033[0;31m"
#define RESET "\033[0m"

void test_one() {
	std::cout << RED "test from the subject:" RESET << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_two() {
	std::cout << RED "test with a sequence:" RESET << std::endl;

	Span sp = Span(5);

	std::vector<int> sequence;
	sequence.push_back(6);
	sequence.push_back(3);
	sequence.push_back(17);
	sequence.push_back(9);
	sequence.push_back(11);

	sp.addSequence(sequence);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_three() {
	std::cout << RED "test exceptions:" RESET << std::endl;

	Span sp = Span(0);

	try {
		sp.addNumber(6);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		sp.addSequence(std::vector<int>(1, 6));
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}	

void test_four() {
	std::cout << RED "unpacking the big guns now:" RESET << std::endl;

	std::vector<int> sequence;
	for (int i = 0; i < 100000; ++i) {
		// random number between 0 and 100000
		int random = std::rand() % 100000;
		sequence.push_back(random);
	}

	Span sp = Span(100000);
	*sequence.begin() = 0;
	*(sequence.end() - 1) = std::numeric_limits<int>::max();
	sp.addSequence(sequence);
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(100000);
	*sequence.begin() = 0;
	*(sequence.end() - 1) = 0;
	sp2.addSequence(sequence);
	std::cout << sp2.shortestSpan() << std::endl;
}

int main()
{
	test_one();
	test_two();
	test_three();
	test_four();
	return 0;
}