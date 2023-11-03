#ifndef MergeSort_HPP_
#define MergeSort_HPP_

#include <vector>

typedef unsigned int uint;

template <typename Container>
class MergeSort {
	public:
		static void sort(Container& vec, int start, int end);
	private:
		MergeSort();
		~MergeSort();
		MergeSort(const MergeSort & obj);
		MergeSort& operator=(const MergeSort& obj);
};

#endif  // MergeSort_HPP_
