
#include "Zombie.hpp" // Zombie class

int	main(void)
{
	Zombie*	zombie = newZombie("Seppel");
	zombie->announce();

	randomChump("Gertrud");
	randomChump("Hans");

	delete zombie;
	return (0);
}
