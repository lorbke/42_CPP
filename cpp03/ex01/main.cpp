
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// @note copy assignment operator?

int	main(void)
{
	ClapTrap	Tim("Tim");
	ClapTrap	Tom("Tom");
	Tim.attack("Tom");
	Tom.takeDamage(1);
	Tom.beRepaired(1);

	ScavTrap	Jim("Jim");
	ScavTrap	Jack("Jack");
	Jim.attack("Jack");
	Jack.takeDamage(1);
	Jack.beRepaired(1);
	Jim.guardGate();
	return (0);
}
