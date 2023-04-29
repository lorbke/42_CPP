
#include "DiamondTrap.hpp"
#include <iostream>

// @note copy assignment operator?
// @todo make ClapTrap private attributes protected instead, this way no setters and getters are needed, apply on all exercises

int	main(void)
{
	DiamondTrap	Bill("Bill");
	std::cout << std::endl;

	DiamondTrap	Bob("Bob");
	std::cout << std::endl;

	Bill.whoAmI();
	std::cout << std::endl;

	Bob.attack("Bill");
	std::cout << Bob.getEnergyPoints() << std::endl;
	std::cout << Bob.getHitPoints() << std::endl;
	Bob.takeDamage(10);
	Bob.beRepaired(10);
	std::cout << std::endl;

	return (0);
}
