
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

Dog&	Dog::operator=(const Dog& src)
{
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
