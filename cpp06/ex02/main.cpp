#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <math.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

Base* generate(void) {
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "undefined" << std::endl;
}

void identify(Base& p) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	std::cout << "undefined" << std::endl;
}

void test_one() {
	std::cout << "test one:" << std::endl;
	Base* ptr = generate();

	identify(ptr);

	delete ptr;
}

void test_two() {
	std::cout << "test two:" << std::endl;
	Base& ref = *generate();

	identify(ref);

	delete &ref; // lol! confusing dangerous shit
}

int main() {
	srand(std::time(NULL)); // generate seed for random number generation
    test_one();
	test_two();

    return 0;
}