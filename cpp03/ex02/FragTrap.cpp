
#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap "
	<< this->getName()
	<< " has been created!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap "
	<< this->getName()
	<< " has been created as a copy from"
	<< src.getName()
	<< "!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "
	<< this->getName()
	<< " has been destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "
	<< this->getName()
	<< " is requesting a high five, guys!" << std::endl;
}
