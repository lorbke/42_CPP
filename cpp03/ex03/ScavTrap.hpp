
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap(std::string name);
					ScavTrap(const ScavTrap& src);
					~ScavTrap();
		void		guardGate(void);
		void		attack(const std::string& target);
	private:
};

#endif
