
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout
	<< this->name
	<< " attacks with their "
	<< this->weapon->getType()
	<< std::endl;
}
