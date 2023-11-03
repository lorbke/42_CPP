#include "Debug.hpp"
#include <iostream>
#include <iomanip> // setw
#include <vector>
#include <deque>

template <typename Container>
Debug<Container>::Debug() {}

template <typename Container>
Debug<Container>::~Debug() {}

template <typename Container>
Debug<Container>::Debug(const Debug<Container>& obj) { *this = obj; }

template <typename Container>
Debug<Container>& Debug<Container>::operator=(const Debug<Container>& obj) {
	(void)obj;
	return *this;
}

template <typename Container>
int get_field_width(Container& container) {
	uint largest = 0;
	for (typename Container::iterator it = container.begin(); it != container.end(); it++) {
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

template <typename Container>
void Debug<Container>::print_input(char** argv) {
	#ifdef DEBUG
		for (int i = 0; argv[i]; i++) {
			std::cout << argv[i] << std::endl;
		}
	#endif
	(void)argv;
}

template <typename Container>
void Debug<Container>::print_container(Container& container) {
	#ifdef DEBUG
		for(typename Container::iterator it = container.begin(); it != container.end(); ++it) {
			std::cout <<  "[ " << *it << " ]";
		}
		std::cout << std::endl;
	#endif
	(void)container;
}

template <typename Container>
void print_container_yellow(Container& container, uint insert_val) {
	int width = get_field_width(container);
		for(typename Container::iterator it = container.begin(); it != container.end(); ++it) {
			if (*it == insert_val)
				std::cout << YELLOW "[ " << std::setw(width) << *it << " ]" RESET;
			else
				std::cout <<  "[ " << std::setw(width) << *it << " ]";
		}
	std::cout << std::endl;
}

template <typename Container>
void Debug<Container>::print_container_insert(Container& dest, Container& src, uint insert_val) {
	#ifdef DEBUG
		print_container_yellow(dest, insert_val);
		std::cout << YELLOW "inserted number, according to jacobsthal-sequence: " RESET << std::endl;
		print_container_yellow(src, insert_val);
		std::cout << std::endl;
	#endif
	(void)dest;
	(void)src;
	(void)insert_val;
}

template <typename Container>
void Debug<Container>::print_container_bisearch(Container& container, uint insert_val) {
	#ifdef DEBUG
		int width = get_field_width(container);
		for(typename Container::iterator it = container.begin(); it != container.end(); ++it) {
			if (*it == insert_val)
				std::cout << BLUE "[ " << std::setw(width) << *it << " ]" RESET;
			else
				std::cout <<  "[ " << std::setw(width) << *it << " ]";
		}
		std::cout << std::endl;
	#endif
	(void)container;
	(void)insert_val;
}

template <typename Container>
void Debug<Container>::container_sorted(Container& container) {
	#ifdef DEBUG
		for (size_t i = 1; i < container.size(); ++i) {
			if (container[i-1] > container[i]) {
				std::cout << RED "-------container not sorted!------" RESET << std::endl;
				return ;
			}
		}
		std::cout << GREEN "---------container sorted!--------" RESET << std::endl;
	#endif
	(void)container;
}

// necessary to avoid linker error, explicitly instantiates template class
template class Debug<std::vector<uint> >;
template class Debug<std::deque<uint> >;