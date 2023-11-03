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
		std::vector<uint>& get_vec();
		std::vector<uint>& get_sorted();
		void sort();

	private:
		std::vector<uint> vec;
		std::vector<uint> sorted;
};

#endif  // PMERGEME_HPP_
