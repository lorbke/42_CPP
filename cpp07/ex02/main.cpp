#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void print_arr(Array<T>& arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
}

int main(void) {
	std::cout << "empty int array:" << std::endl;
	Array<int> int_arr_empty = Array<int>();
	print_arr(int_arr_empty);

	std::cout << "int array:" << std::endl;
	Array<int> int_arr = Array<int>(5);
	print_arr(int_arr);

	std::cout << "string array:" << std::endl;
	Array<std::string> str_arr = Array<std::string>(5);
	str_arr[0] = "4200000 string shit";
	print_arr(str_arr);

	std::cout << "int array from copy assignment operator:" << std::endl;
	int_arr[0] = 42;
	Array<int>* int_arr_ptr = &int_arr;
	print_arr(*int_arr_ptr);

	std::cout << "int array from copy constructor:" << std::endl;
	int_arr[1] = 42;
	Array<int> int_arr_copy = Array<int>(int_arr);
	print_arr(int_arr_copy);

	std::cout << "string array size:" << std::endl;
	std::cout << str_arr.size() << std::endl;

	std::cout << "out of bounds exception:" << std::endl;
	try {
		int_arr[10] = 42;
	}
	catch(const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}