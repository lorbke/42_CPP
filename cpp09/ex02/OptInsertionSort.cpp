#include "OptInsertionSort.hpp"
#include "Debug.hpp"
#include <vector>
#include <iostream>

#define JCBSIZE 27

static uint jcbsqnce[JCBSIZE] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691,
87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971};

OptInsertionSort::OptInsertionSort() {}

OptInsertionSort::~OptInsertionSort() {}

OptInsertionSort::OptInsertionSort(const OptInsertionSort & obj) { *this = obj; }

OptInsertionSort& OptInsertionSort::operator=(const OptInsertionSort& obj) {
	(void)obj;
	return *this;
}

// middle == vec.end() check is unnecessary,
// preceding merge sort already places the greater pair elements in the vector.
void binary_search_insert(std::vector<uint>& dest, uint value, int start, int end) {
	uint middle = start + (end - start) / 2;
	Debug::print_vec_bisearch(dest, dest[middle]);
	if (middle == 0) {
		if (dest[middle] >= value)
			dest.insert(dest.begin(), value);
		else
			dest.insert(dest.begin() + 1, value);
		return ;
	}
	if (dest[middle] > value)
		binary_search_insert(dest, value, start, middle);
	else if (dest[middle + 1] < value)
		binary_search_insert(dest, value, middle + 1, end);
	else
		dest.insert(dest.begin() + middle + 1, value);
}

uint get_last_jcbsnum(uint vec_size) {
	if (vec_size <= jcbsqnce[0])
		return 0;

	uint i = 0;
	for (; i < JCBSIZE; i++) {
		if (vec_size <= jcbsqnce[i]) {
			break;
		}
	}
	return i - 1;
}

void OptInsertionSort::sort(std::vector<uint>& dest, std::vector<uint>& src) {
	if (src.size() == 0)
		return ;
	uint end = get_last_jcbsnum(src.size());
	int start = (src.size() < jcbsqnce[0]) ? src.size() - 1 : jcbsqnce[0] - 1;
	for (int i = start; i >= 0; i--) {
		binary_search_insert(dest, src[i], 0, dest.size() - 1);
		Debug::print_vec_insert(dest, src, src[i]);
	}
	for (uint i = 1; i <= end; i++) {
		for (uint j = jcbsqnce[i] - 1; j >= jcbsqnce[i - 1]; j--) {
			binary_search_insert(dest, src[j], 0, dest.size() - 1);
			Debug::print_vec_insert(dest, src, src[j]);
		}
	}
	for (uint i = src.size() - 1; i >= jcbsqnce[end]; i--) {
		binary_search_insert(dest, src[i], 0, dest.size() - 1);
		Debug::print_vec_insert(dest, src, src[i]);
	}
}