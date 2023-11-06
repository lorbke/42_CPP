#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <math.h>
#include <iostream>
#include <cstdlib>

Base::~Base() {
}

Base* Base::generate(void) {
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

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "undefined" << std::endl;
}

void Base::identify(Base& p) {

	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {};
	std::cout << "undefined" << std::endl;
}