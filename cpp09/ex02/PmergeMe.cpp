#include "PmergeMe.hpp"
#include "MergeSort.hpp"
#include "OptInsertionSort.hpp"
#include "Debug.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <iomanip> // setw

typedef unsigned int uint;

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(Container cont) : vec(cont) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe & obj) { *this = obj; }

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

template <typename Container>
Container& PmergeMe<Container>::get_vec() {
	return vec;
}

template <typename Container>
Container& PmergeMe<Container>::get_sorted() {
	return sorted;
}

template <typename Container>
void split_vec_into_pairs(Container& sorted, Container& vec) {
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

template <typename Container>
void PmergeMe<Container>::sort() {
	split_vec_into_pairs(sorted, vec);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "list of greater pair elements: " RESET << std::endl;
		Debug<Container>::print_vec(sorted);
	#endif
	MergeSort<Container>::sort(sorted, 0, sorted.size() - 1);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "merge sorted list of greater pair elements: " RESET << std::endl;
		Debug<Container>::print_vec(sorted);
		std::cout << "\n" << BLUE "optimized insertion sort of smaller pair elements into list of greater pair elements: " RESET << std::endl;
	#endif
	OptInsertionSort<Container>::sort(sorted, vec);
}

// necessary to avoid linker error, explicitly instantiates template class
template class PmergeMe<std::vector<uint> >;
template class PmergeMe<std::deque<uint> >;