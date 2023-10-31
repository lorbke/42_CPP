#include "mergeSort.hpp"
#include <vector>
#include <iomanip>
#include <iostream>

mergeSort::mergeSort() {}

mergeSort::~mergeSort() {}

mergeSort::mergeSort(const mergeSort & obj) { *this = obj; }

mergeSort& mergeSort::operator=(const mergeSort& obj) {
	(void)obj;
	return *this;
}

void merge(std::vector<uint>& vec, int start, int middle, int end) {
	std::vector<uint> left(vec.begin() + start, vec.begin() + middle + 1);
	std::vector<uint> right(vec.begin() + middle + 1, vec.begin() + end + 1);
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

void mergeSort::sort(std::vector<uint>& vec, int start, int end) {
	if (start >= end)
		return;
	int middle = start + (end - start) / 2;
	sort(vec, start, middle);
	sort(vec, middle + 1, end);
	merge(vec, start, middle, end);
}