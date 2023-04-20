
#include "Zombie.hpp" // Zombie class

void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
}
