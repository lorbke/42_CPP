#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

void merge_sort(std::vector<uint> numbers, int count) {
	// if count = 1
		// return

	// merge_sort left (end of numbers at count)
	// merge_sort right (start of numbers at count)

	// merge together function
}

void PmergeMe::sort_numbers() {
	merge_sort(this->numbers, this->numbers.size());
}
