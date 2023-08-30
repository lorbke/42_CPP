#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & obj);
		MutantStack& operator=(const MutantStack& obj);
		iterator begin();
		iterator end();
	private:
};

#include "MutantStack.tpp"

#endif  // MUTANTSTACK_HPP_