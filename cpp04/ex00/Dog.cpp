
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	this->_type = src._type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}
