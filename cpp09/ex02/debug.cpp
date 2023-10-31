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

void debug_print_input(char** argv) {
    for (int i = 0; argv[i]; i++) {
       std::cout << argv[i] << std::endl;
    }
}

void debug_print_vec(std::vector<uint>& vec) {
	for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << std::setw(7) <<  "[ " << *it << " ]";
	}
	std::cout << std::endl;
}