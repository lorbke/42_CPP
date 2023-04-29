
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap "
	<< this->getName()
	<< " has been created!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap "
	<< this->getName()
	<< " has been created as a copy from"
	<< src.getName()
	<< "!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "
	<< this->getName()
	<< " has been destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		return ;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap "
	<< this->getName()
	<< " attacks "
	<< target
	<< ", causing "
	<< this->getAttackDamage()
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap "
	<< this->getName()
	<< " is now in Gate keeper mode." << std::endl;
}
