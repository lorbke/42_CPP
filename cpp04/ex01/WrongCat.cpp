
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	this->_type = src._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}
