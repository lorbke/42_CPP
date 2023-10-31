#ifndef MergeSort_HPP_
#define MergeSort_HPP_

#include <vector>

typedef unsigned int uint;

class MergeSort {
	public:
		static void sort(std::vector<uint>& vec, int start, int end);
	private:
		MergeSort();
		~MergeSort();
		MergeSort(const MergeSort & obj);
		MergeSort& operator=(const MergeSort& obj);
};

#endif  // MergeSort_HPP_
