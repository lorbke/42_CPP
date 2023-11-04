#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <math.h>

void test_one() {
	std::cout << "test one:" << std::endl;
    Base  base;
	Base* ptr = base.generate();

	base.identify(ptr);

	delete ptr;
}

void test_two() {
	std::cout << "test two:" << std::endl;
	Base  base;
	Base& ref = *base.generate();

	base.identify(ref);

	delete &ref; // lol! confusing dangerous shit
}

int main() {
	srand(std::time(NULL)); // generate seed for random number generation
    test_one();
	test_two();

    return 0;
}