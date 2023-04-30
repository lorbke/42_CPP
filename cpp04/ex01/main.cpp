
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define COUNT 10

// @note the trick here was to declare the Animal destructor as virtual, so that the destructors of derived classes are also called

int	main(void)
{
	Animal	*animals[COUNT];

	std::cout << "CONSTRUCTIONS: " << std::endl;
	for (int i = 0; i < COUNT / 2; i++)
		animals[i] = new Cat();
	for (int i = 5; i < COUNT; i++)
		animals[i] = new Dog();
	std::cout << std::endl;

	std::cout << "TEST1: " << std::endl;
	animals[0]->makeSound();
	animals[5]->makeSound();
	std::cout << std::endl;

	std::cout << "TEST2: " << std::endl;
	std::cout << animals[0]->getType() << std::endl;
	*animals[0] = *animals[5];
	std::cout << animals[0]->getType() << std::endl;
	animals[0]->makeSound();
	std::cout << std::endl;

	std::cout << "DESTRUCTIONS: " << std::endl;
	for (int i = 0; i < COUNT; i++)
		delete animals[i];
	std::cout << std::endl;

	return (0);
}
