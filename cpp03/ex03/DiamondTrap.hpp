
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
				DiamondTrap(std::string name);
				~DiamondTrap();
		using	ScavTrap::attack;
		void	whoAmI();
	private:
		std::string _name;
};

#endif
