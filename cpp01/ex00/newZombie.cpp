
#include "Zombie.hpp" // Zombie class
#include <string> // string

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = new Zombie(name);
	return (zombie);
}
