#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // setw

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

typedef std::vector<uint>::iterator iter;

void debug_print_vector(std::vector<uint> vec);

// @todo implement correct canonical form
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

void merge(std::vector<uint>& left, std::vector<uint>& right) {
	#ifdef DEBUG
		std::cout << BLUE "left, right: " RESET << std::endl;
		debug_print_vector(left);
		debug_print_vector(right);
	#endif

	for (iter it_r = right.begin(); it_r != right.end(); ++it_r) {
		iter it_l = left.begin();
		for (; it_l != left.end(); ++it_l) {
			if (*it_l > *it_r) {
				left.insert(it_l, *it_r);
				break;
			}
		}
		if (it_l == left.end())
			left.push_back(*it_r);
	}

	#ifdef DEBUG
		std::cout << BLUE "merged: " RESET << std::endl;
		debug_print_vector(left);
		std::cout << std::endl;
	#endif
}

std::vector<uint> merge_sort(std::vector<uint> numbers, int count) {
	if (count == 1)
		return numbers;

	#ifdef DEBUG
		std::cout << BLUE "level " RESET << count << std::endl;
	#endif

	std::vector<uint> left(numbers.begin(), numbers.begin() + count / 2);
	std::vector<uint> right(numbers.begin() + count / 2, numbers.end());

	left = merge_sort(left, count / 2);
	right = merge_sort(right, count / 2);

	merge(left, right);

	return (left);
}

void PmergeMe::sort_numbers() {
	this->numbers = merge_sort(this->numbers, this->numbers.size());
}
