
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

Cat&	Cat::operator=(const Cat& src)
{
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
