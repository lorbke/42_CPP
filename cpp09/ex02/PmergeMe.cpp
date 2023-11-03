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
PmergeMe<Container>::PmergeMe(Container cont) : container(cont) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe & obj) {
	*this = obj;
	container = obj.get_container();
	result = obj.get_result();
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& obj) {
	container = obj.get_container();
	result = obj.get_result();
	return *this;
}

template <typename Container>
Container PmergeMe<Container>::get_container() const {
	return container;
}

template <typename Container>
Container PmergeMe<Container>::get_result() const {
	return result;
}

template <typename Container>
Container& PmergeMe<Container>::get_container() {
	return container;
}

template <typename Container>
Container& PmergeMe<Container>::get_result() {
	return result;
}

template <typename Container>
void split_container_into_pairs(Container& result, Container& container) {
	for (uint i = 0; i < container.size() - 1; i++) {
		if (container[i] > container[i + 1]) {
			result.push_back(container[i]);
			container.erase(container.begin() + i);
		} else {
			result.push_back(container[i + 1]);
			container.erase(container.begin() + i + 1);
		}
	}
	result.insert(result.begin(), container[0]);
	container.erase(container.begin());
}

template <typename Container>
void PmergeMe<Container>::sort() {
	split_container_into_pairs(result, container);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "list of greater pair elements: " RESET << std::endl;
		Debug<Container>::print_container(result);
	#endif
	MergeSort<Container>::sort(result, 0, result.size() - 1);
	#ifdef DEBUG
		std::cout << "\n" << BLUE "merge result list of greater pair elements: " RESET << std::endl;
		Debug<Container>::print_container(result);
		std::cout << "\n" << BLUE "optimized insertion sort of smaller pair elements into list of greater pair elements: " RESET << std::endl;
	#endif
	OptInsertionSort<Container>::sort(result, container);
}

// necessary to avoid linker error, explicitly instantiates template class
template class PmergeMe<std::vector<uint> >;
template class PmergeMe<std::deque<uint> >;