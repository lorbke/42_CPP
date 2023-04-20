
#include "Zombie.hpp" // Zombie class

int	main(void)
{
	int	count = 5;
	Zombie*	zombies = zombieHorde(count, "Bob");

	for (int i = 0; i < count; i++)
		zombies[i].announce();
	
	// [] necessary because zombies refers to an array of objects
	delete [] zombies;

	return (0);
}
