#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

template <typename Container>
class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(Container cont);
		~PmergeMe();
		PmergeMe(const PmergeMe<Container>& obj);
		PmergeMe<Container>& operator=(const PmergeMe<Container>& obj);
		Container get_container() const;
		Container get_result() const;
		Container& get_container();
		Container& get_result();
		void sort();

	private:
		Container container;
		Container result;
};

#endif  // PMERGEME_HPP_
