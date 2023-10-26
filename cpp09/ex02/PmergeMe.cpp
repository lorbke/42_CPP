#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // setw

typedef std::vector<uint>::iterator iter;

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

void merge(std::vector<uint>& left, std::vector<uint>& right) {
	#ifdef DEBUG
		std::cout << "left, right: " << std::endl;
		print_vector_state(left);
		print_vector_state(right);
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
		std::cout << "merged: " << std::endl;
		print_vector_state(left);
	#endif
}

std::vector<uint> merge_sort(std::vector<uint> numbers, int count) {
	if (count == 1)
		return numbers;

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
