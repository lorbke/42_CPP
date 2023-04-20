
#include "Zombie.hpp" // Zombie class
#include <iostream> // cout

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout
	<< this->name
	<< " died."
	<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout
	<< this->name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}
