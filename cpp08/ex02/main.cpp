#include "MutantStack.hpp"
#include <iostream>
#include <vector>

#define RED "\033[0;31m"
#define RESET "\033[0m"

void test_one() {
	std::cout << RED "test from subject:" RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test_two() {
	std::cout << RED "comparison test with vector:" RESET << std::endl;

	std::vector<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << *(mstack.end() - 1) << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
}

void test_three() {
	std::cout << RED "testing operator=:" RESET << std::endl;

	MutantStack<int> mstack;
	MutantStack<int> mstack2;

	mstack.push(5);
	mstack.push(17);

	mstack2 = mstack;

	std::cout << mstack.top() << std::endl;
	std::cout << mstack2.top() << std::endl;
}

void test_four() {
	std::cout << RED "testing copy constructor:" RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	MutantStack<int> mstack2(mstack);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack2.top() << std::endl;
}

int main()
{
	test_one();
	test_two();
	test_three();
	test_four();
	return 0;
}