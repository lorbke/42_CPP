#include "PmergeMe.hpp"
#include "StopWatch.hpp"
#include "Debug.hpp"
#include <iostream> // io, uint
#include <iomanip> // setw
#include <cstdlib> // strtol
#include <cctype> // isalnum
#include <cerrno>
#include <climits>
#include <vector>

void print_vector(std::vector<uint> vec) {
	for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
}

bool is_str_only_num(char* str) {
	for (int i = 0; str[i]; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

int parse(char** input, std::vector<uint>& numbers) {
	errno = 0;

	for (int i = 0; input[i]; i++) {
		if (!is_str_only_num(input[i]))
			return 1;
		numbers.push_back(strtol(input[i], NULL, 10));
		if (errno == ERANGE || numbers.back() > INT_MAX)
			return 2;
	}
	return 0;
}

// @todo rename vec to container
// @todo follow orthodox canonical class form
// @todo rename sorted to result

int main(int argc, char** argv) {
	if (argc <= 1) {
		std::cerr << "usage: pmergeme { value }" << std::endl;
		return 1;
	}

	PmergeMe<std::vector<uint> > sorter;
	StopWatch timer;

	switch (parse(++argv, sorter.get_vec()))
	{
		case 0:
			#ifdef DEBUG
				std::cout << BLUE "parsing success!" RESET << std::endl;
			#endif
			break;
		case 1:
			std::cerr << "error: wrong input: invalid chars" << std::endl;
			return 1;
		case 2:
		std::cerr << "error: wrong input: range error" << std::endl;
		return 2;
	}

	std::cout << "before: ";
	print_vector(sorter.get_vec());
	std::cout << std::endl;

	timer.start();
	sorter.sort();
	timer.stop();

	std::cout << "after:  ";
	print_vector(sorter.get_sorted());
	std::cout << std::endl;

	Debug<std::vector<uint> >::vec_sorted(sorter.get_sorted());

	std::cout << "Time to process a range of " <<
	argc - 1 << " elements with std::vector : " 
	<< timer.get_time_in_ms() << " ms" <<  std::endl;

	return 0;
}