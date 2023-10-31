#ifndef OPTINSERTIONSORT_HPP_
#define OPTINSERTIONSORT_HPP_

#include <vector>

typedef unsigned int uint;

class OptInsertionSort {
	public:
		static void sort(std::vector<uint>& to, std::vector<uint>& from);
	private:
		OptInsertionSort();
		~OptInsertionSort();
		OptInsertionSort(const OptInsertionSort & obj);
		OptInsertionSort& operator=(const OptInsertionSort& obj);
};

#endif  // OPTINSERTIONSORT_HPP_
