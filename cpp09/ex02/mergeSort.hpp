#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

#include <vector>

typedef unsigned int uint;

class mergeSort {
	public:
		static void sort(std::vector<uint>& vec, int start, int end);
	private:
		mergeSort();
		~mergeSort();
		mergeSort(const mergeSort & obj);
		mergeSort& operator=(const mergeSort& obj);
};

#endif  // MERGESORT_HPP_
