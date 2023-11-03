#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <iostream> // uint
#include <vector>

template <typename Container>
class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe<Container>& obj);
		PmergeMe<Container>& operator=(const PmergeMe<Container>& obj);
		Container& get_vec();
		Container& get_sorted();
		void sort();

	private:
		Container vec;
		Container sorted;
};

#endif  // PMERGEME_HPP_
