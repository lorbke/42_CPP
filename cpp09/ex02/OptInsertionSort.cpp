#include "OptInsertionSort.hpp"
#include <vector>
#include <iostream>

static int jcbsqnce[27] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691,
87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971};

OptInsertionSort::OptInsertionSort() {}

OptInsertionSort::~OptInsertionSort() {}

OptInsertionSort::OptInsertionSort(const OptInsertionSort & obj) { *this = obj; }

OptInsertionSort& OptInsertionSort::operator=(const OptInsertionSort& obj) {
	(void)obj;
	return *this;
}

void OptInsertionSort::sort(std::vector<uint>& to, std::vector<uint>& from) {
	to = from;
	int end = 0;
	uint total = 0;
	for (uint i = 0; i < 27; i++) {
		total += jcbsqnce[i];
		if (from.size() < total) {
			end = i - 1;
			break;
		}
	}

	for (int i = 0; i <= end; i++) {
		for (int j = jcbsqnce[i]; j > jcbsqnce[i - 1]; j--) {
			std::cout << j << std::endl;
		}
	}

	#ifdef DEBUG
		std::cout << "last jacobsthal number: " << end << std::endl;
		std::cout << "form size: " << from.size() << std::endl;
	#endif
}