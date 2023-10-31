#include "PmergeMe.hpp"
#include "MergeSort.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // setw

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

typedef std::vector<uint>::iterator iter;
typedef unsigned int uint;

// @todo implement correct canonical form
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

void split_vec_into_pairs(std::vector<uint>& sorted, std::vector<uint>& vec) {
	for (uint i = 0; i < vec.size() - 1; i++) {
		if (vec[i] > vec[i + 1]) {
			sorted.push_back(vec[i]);
			vec.erase(vec.begin() + i);
		} else {
			sorted.push_back(vec[i + 1]);
			vec.erase(vec.begin() + i + 1);
		}
	}
	sorted.insert(sorted.begin(), vec[0]);
	vec.erase(vec.begin());
}

void PmergeMe::sort() {
	split_vec_into_pairs(this->sorted, this->vec);
	MergeSort::sort(this->sorted, 0, this->sorted.size() - 1);
}
