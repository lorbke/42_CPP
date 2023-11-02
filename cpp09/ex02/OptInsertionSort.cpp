#include "OptInsertionSort.hpp"
#include <vector>
#include <iostream>

static uint jcbsqnce[27] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691,
87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971};

OptInsertionSort::OptInsertionSort() {}

OptInsertionSort::~OptInsertionSort() {}

OptInsertionSort::OptInsertionSort(const OptInsertionSort & obj) { *this = obj; }

OptInsertionSort& OptInsertionSort::operator=(const OptInsertionSort& obj) {
	(void)obj;
	return *this;
}

uint get_last_jcbsnum(uint vec_size) {
	if (vec_size <= jcbsqnce[0])
		return 0;

	uint i = 0;
	for (; i < 27; i++) {
		if (vec_size <= jcbsqnce[i]) {
			break;
		}
	}
	return i - 1;
}

void OptInsertionSort::sort(std::vector<uint>& to, std::vector<uint>& from) {
	if (from.size() == 0)
		return ;

	to = from;
	uint end = get_last_jcbsnum(from.size());
	#ifdef DEBUG
		std::cout << "last jacobsthal number: " << jcbsqnce[end] << std::endl;
		std::cout << "from size: " << from.size() << std::endl;
	#endif


	int start = (from.size() < jcbsqnce[0]) ? from.size() - 1 : jcbsqnce[0] - 1;
	for (int i = start; i >= 0; i--)
		std::cout << i << std::endl;
	for (uint i = 1; i <= end; i++) {
		for (uint j = jcbsqnce[i] - 1; j >= jcbsqnce[i - 1]; j--)
			std::cout << j << std::endl;
	}
	for (uint i = from.size() - 1; i >= jcbsqnce[end]; i--) {
		std::cout << i << std::endl;
	}

	// for (uint i = 0; i <= end; i++) {
	// 	for (uint j = jcbsqnce[i]; j > jcbsqnce[i - 1]; j--) {
	// 		std::cout << j << std::endl;
	// 	}
	// }
	// for (uint i = from.size() - 1; i > jcbsqnce[end]; i--) {
	// 	std::cout << i << std::endl;
	// }
}