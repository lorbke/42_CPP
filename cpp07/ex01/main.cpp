#include "iter.hpp"
#include <string>
#include <iostream>

template <typename T>
void print(T& value) {
	std::cout << value << std::endl;
}

int main(void) {
	int         arr_len = 5;
	int         int_arr[] = {1, 2, 3, 4, 5};
	std::string str_arr[] = {"one", "two", "three", "four", "five"};
	char        char_arr[] = {'a', 'b', 'c', 'd', 'e'};

	::iter(int_arr, arr_len, &print<int>);
	::iter(str_arr, arr_len, &print<std::string>);
	::iter(char_arr, arr_len, &print<char>);

	return 0;
}