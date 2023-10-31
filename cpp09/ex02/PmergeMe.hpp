#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream> // uint
#include <vector>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & obj);
		PmergeMe& operator=(const PmergeMe& obj);
		std::vector<uint> vec;
		std::vector<uint> sorted;
		void sort();

	private:
};

#endif  // PMERGEME_HPP_
