
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

#define COUNT 10

int	main(void)
{
	Animal	*animals[COUNT];

	std::cout << GREEN "CONSTRUCTIONS: " RESET << std::endl;
	for (int i = 0; i < COUNT / 2; i++)
		animals[i] = new Cat();
	for (int i = 5; i < COUNT; i++)
		animals[i] = new Dog();
	std::cout << std::endl;

	std::cout << GREEN "TEST1: " RESET << std::endl;
	animals[0]->makeSound();
	animals[5]->makeSound();
	std::cout << std::endl;

	std::cout << GREEN "TEST2: " RESET << std::endl;
	std::cout << animals[0]->getType() << std::endl;
	*animals[0] = *animals[5];
	std::cout << animals[0]->getType() << std::endl;
	animals[0]->makeSound();
	std::cout << std::endl;

	std::cout << GREEN "DESTRUCTIONS: " RESET << std::endl;
	for (int i = 0; i < COUNT; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << GREEN "SUBJECT TEST: " RESET << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return (0);
}
