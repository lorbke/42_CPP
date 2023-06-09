
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->_type = src._type;
}

Cat&	Cat::operator=(const Cat& src)
{
	this->_type = src._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
