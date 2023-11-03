#include "MergeSort.hpp"
#include <vector>
#include <deque>
#include <iomanip>
#include <iostream>

template <typename Container>
MergeSort<Container>::MergeSort() {}

template <typename Container>
MergeSort<Container>::~MergeSort() {}

template <typename Container>
MergeSort<Container>::MergeSort(const MergeSort<Container>& obj) { *this = obj; }

template <typename Container>
MergeSort<Container>& MergeSort<Container>::operator=(const MergeSort<Container>& obj) {
	(void)obj;
	return *this;
}

template <typename Container>
void merge(Container& vec, int start, int middle, int end) {
	Container left(vec.begin() + start, vec.begin() + middle + 1);
	Container right(vec.begin() + middle + 1, vec.begin() + end + 1);
	uint i = 0, j = 0, k = start;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			vec[k] = left[i];
			i++;
		} else {
			vec[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left.size()) {
		vec[k] = left[i];
		i++;
		k++;
 	}
	while (j < right.size()) {
 		vec[k] = right[j];
 		j++;
 		k++;
	}
}

template <typename Container>
void MergeSort<Container>::sort(Container& vec, int start, int end) {
	if (start >= end)
		return;
	int middle = start + (end - start) / 2;
	sort(vec, start, middle);
	sort(vec, middle + 1, end);
	merge(vec, start, middle, end);
}

// necessary to avoid linker error, explicitly instantiates template class
template class MergeSort<std::vector<uint> >;
template class MergeSort<std::deque<uint> >;