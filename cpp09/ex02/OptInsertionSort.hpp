#ifndef OPTINSERTIONSORT_HPP_
#define OPTINSERTIONSORT_HPP_

#include <vector>

typedef unsigned int uint;

template <typename Container>
class OptInsertionSort {
	public:
		static void sort(Container& to, Container& from);
	private:
		OptInsertionSort();
		~OptInsertionSort();
		OptInsertionSort(const OptInsertionSort & obj);
		OptInsertionSort& operator=(const OptInsertionSort& obj);
};

#endif  // OPTINSERTIONSORT_HPP_
