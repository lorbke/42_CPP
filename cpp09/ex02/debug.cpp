#include "Debug.hpp"
#include <iostream>
#include <iomanip> // setw
#include <vector>

Debug::Debug() {}

Debug::~Debug() {}

Debug::Debug(const Debug & obj) { *this = obj; }

Debug& Debug::operator=(const Debug& obj) {
	(void)obj;
	return *this;
}

int get_field_width(std::vector<uint>& vec) {
	uint largest = 0;
	for (std::vector<uint>::iterator it = vec.begin(); it != vec.end(); it++) {
		if (*it > largest)
			largest = *it;
	}
	int width = 0;
	while (largest) {
		width++;
		largest /= 10;
	}
	return width;
}

void Debug::print_input(char** argv) {
	#ifdef DEBUG
		for (int i = 0; argv[i]; i++) {
			std::cout << argv[i] << std::endl;
		}
	#endif
	(void)argv;
}

void Debug::print_vec(std::vector<uint>& vec) {
	#ifdef DEBUG
		for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
			std::cout <<  "[ " << *it << " ]";
		}
		std::cout << std::endl;
	#endif
	(void)vec;
}

void Debug::print_vec_insert(std::vector<uint>& vec, uint insert_val) {
	#ifdef DEBUG
		int width = get_field_width(vec);
		for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
			if (*it == insert_val)
				std::cout << YELLOW "[ " << std::setw(width) << *it << " ]" RESET;
			else
				std::cout <<  "[ " << std::setw(width) << *it << " ]";
		}
		std::cout << std::endl;
		std::cout << YELLOW "inserted value: " << insert_val << RESET << "\n" << std::endl;
	#endif
	(void)vec;
	(void)insert_val;
}

void Debug::print_vec_bisearch(std::vector<uint>& vec, uint insert_val) {
	#ifdef DEBUG
		int width = get_field_width(vec);
		for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
			if (*it == insert_val)
				std::cout << BLUE "[ " << std::setw(width) << *it << " ]" RESET;
			else
				std::cout <<  "[ " << std::setw(width) << *it << " ]";
		}
		std::cout << std::endl;
	#endif
	(void)vec;
	(void)insert_val;
}

void Debug::vec_sorted(std::vector<uint>& vec) {
	#ifdef DEBUG
		for (size_t i = 1; i < vec.size(); ++i) {
			if (vec[i-1] > vec[i]) {
				std::cout << RED "-------vector not sorted!------" RESET << std::endl;
				return ;
			}
		}
		std::cout << GREEN "---------vector sorted!--------" RESET << std::endl;
	#endif
	(void)vec;
}