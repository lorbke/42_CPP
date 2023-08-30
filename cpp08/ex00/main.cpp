#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

// @note dereferencing container.end() is undefined behaviour as unallocated value is read!
// @note why return .end() if value is not occurring instead of exception? the .find() function does the same.
int main(void) {
	std::vector<int> vector;
	vector.push_back(42);
	std::cout << "testing vector with ocurrence true:" << std::endl;
	std::cout << *::easyfind(vector, 42) << std::endl;
	std::cout << "testing vector with ocurrence false:" << std::endl;
	// std::cout << *::easyfind(vector, 24) << std::endl;

	std::deque<int> deque;
	deque.push_back(42);
	std::cout << "testing deque with ocurrence true:" << std::endl;
	std::cout << *::easyfind(deque, 42) << std::endl;
	std::cout << "testing deque with ocurrence false:" << std::endl;
	// std::cout << *::easyfind(deque, 24) << std::endl;

	std::list<int> list;
	list.push_back(42);
	std::cout << "testing list with ocurrence true:" << std::endl;
	std::cout << *::easyfind(list, 42) << std::endl;
	std::cout << "testing list with ocurrence false:" << std::endl;
	// std::cout << *::easyfind(list, 24) << std::endl;

	std::cout << "validate error:" << std::endl;
	if (::easyfind(list, 24) != list.end())
		std::cout << "value was found!" << std::endl;
	else
		std::cout << "value was not found!" << std::endl;

	return 0;
}