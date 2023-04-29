
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// @note copy assignment operator?

int	main(void)
{
	// ClapTrap	Tim("Tim");
	// ClapTrap	Tom("Tom");
	// Tim.attack("Tom");
	// Tom.takeDamage(1);
	// Tom.beRepaired(1);

	// ScavTrap	Jim("Jim");
	// ScavTrap	Jack("Jack");
	// Jim.attack("Jack");
	// Jack.takeDamage(1);
	// Jack.beRepaired(1);
	// Jim.guardGate();

	FragTrap	Joe("Joe");
	FragTrap	Jane("Jane");
	Joe.attack("Jane");
	Jane.takeDamage(1);
	Jane.beRepaired(1);
	Joe.highFivesGuys();

	return (0);
}
