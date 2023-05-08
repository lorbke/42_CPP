
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	j = meta;
	j->makeSound();

	delete meta;
	delete i;

	Dog dog;
	Cat cat;

	std::cout << dog.getType() << " " << std::endl;
	std::cout << cat.getType() << " " << std::endl;

	dog.makeSound();
	cat.makeSound();

	return (0);
}
