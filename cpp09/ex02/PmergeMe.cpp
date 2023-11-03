#include "PmergeMe.hpp"
#include "MergeSort.hpp"
#include "OptInsertionSort.hpp"
#include "Debug.hpp"
#include <vector>
#include <iostream>
#include <iomanip> // setw

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
	split_vec_into_pairs(sorted, vec);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "list of greater pair elements: " RESET << std::endl;
		Debug::print_vec(sorted);
	#endif
	MergeSort::sort(sorted, 0, sorted.size() - 1);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "merge sorted list of greater pair elements: " RESET << std::endl;
		Debug::print_vec(sorted);
		std::cout << "\n" << BLUE "optimized insertion sort of smaller pair elements into list of greater pair elements: " RESET << std::endl;
	#endif
	OptInsertionSort::sort(sorted, vec);
}
