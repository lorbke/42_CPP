
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
	_name(name)
{
	FragTrap::setHitPoints(100);
    ScavTrap::setEnergyPoints(50);
    FragTrap::setAttackDamage(30);

	std::cout << "DiamondTrap "
	<< this->_name
	<< " has been created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " has been destroyed!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " is "
	<< this->ClapTrap::getName()
	<< "!" << std::endl;
}
