#include "Base.hpp"
#include <iostream>

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
    test_one();
	test_two();

    return 0;
}