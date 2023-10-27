#include <iostream>
#include <iomanip> // setw
#include <vector>

void debug_print_input(char** argv) {
    for (int i = 0; argv[i]; i++) {
       std::cout << argv[i] << std::endl;
    }
}

void debug_print_vector(std::vector<uint> vec) {
	for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << std::setw(7) <<  "[ " << *it << " ]";
	}
	std::cout << std::endl;
}