
#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout
	<< this->name
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}
