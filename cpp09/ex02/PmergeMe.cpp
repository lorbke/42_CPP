#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // setw

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

void print_vector_state(std::vector<uint> vec) {
	for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << std::setw(7) <<  "[ " << *it << " ]";
	}
	std::cout << std::endl;
}

std::vector<uint> merge(std::vector<uint> left, std::vector<uint> right) {
	std::vector<uint> result;

	print_vector_state(left);
	print_vector_state(right);

	while (left.size() > 0 || right.size() > 0) {
		if (left.size() == 0) {
			result.push_back(right.front());
			right.erase(right.begin());
			continue;
		} else if (right.size() == 0) {
			result.push_back(left.front());
			left.erase(left.begin());
			continue;
		}
		if (left.front() <= right.front()) {
			result.push_back(left.front());
			left.erase(left.begin());
		} else {
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	print_vector_state(result);

	return (result);
}

std::vector<uint> merge_sort(std::vector<uint> numbers, int count) {
	if (count == 1)
		return numbers;

	std::vector<uint> left(numbers.begin(), numbers.begin() + count / 2);
	std::vector<uint> right(numbers.begin() + count / 2, numbers.end());

	left = merge_sort(left, count / 2);
	right = merge_sort(right, count / 2);

	return (merge(left, right));
}

void PmergeMe::sort_numbers() {
	this->numbers = merge_sort(this->numbers, this->numbers.size());
}
