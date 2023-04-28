
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Tim("Tim");
	ClapTrap	Tom("Tom");

	Tim.attack("Tom");
	Tom.takeDamage(1);
	Tom.beRepaired(1);
	return (0);
}
