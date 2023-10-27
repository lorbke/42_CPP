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

void merge(std::vector<uint>& numbers, int start, int middle, int end) {
	std::vector<uint> left(numbers.begin() + start, numbers.begin() + middle + 1);
	std::vector<uint> right(numbers.begin() + middle + 1, numbers.begin() + end + 1);

	#ifdef DEBUG
		std::cout << BLUE "left, right: " RESET << std::endl;
		debug_print_vector(left);
		debug_print_vector(right);
	#endif

	uint i = 0, j = 0, k = start;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			numbers[k] = left[i];
			i++;
		} else {
			numbers[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size()) {
		numbers[k] = left[i];
		i++;
		k++;
 	}
	while (j < right.size()) {
 		numbers[k] = right[j];
 		j++;
 		k++;
	}

	#ifdef DEBUG
		std::cout << BLUE "merged: " RESET << std::endl;
		debug_print_vector(left);
		std::cout << std::endl;
	#endif
}

void merge_sort(std::vector<uint>& numbers, int start, int end) {
	#ifdef DEBUG
		std::cout << BLUE "level " RESET << end - start << std::endl;
	#endif

	if (start >= end)
		return;

	int middle = start + (end - start) / 2;

	merge_sort(numbers, start, middle);
	merge_sort(numbers, middle + 1, end);

	merge(numbers, start, middle, end);
}

void PmergeMe::sort_numbers() {
	merge_sort(this->numbers, 0, this->numbers.size() - 1);
}
