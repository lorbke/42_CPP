
#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	this->_type = src._type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	if (this->_type == "Animal")
		std::cout << "Generic animal sound..." << std::endl;
	else if (this->_type == "Cat")
		std::cout << "Meow!" << std::endl;
	else if (this->_type == "Dog")
		std::cout << "Woof!" << std::endl;
}
