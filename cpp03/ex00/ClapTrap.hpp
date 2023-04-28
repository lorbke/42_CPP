
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
					ClapTrap(const std::string& name);
					ClapTrap(const ClapTrap& src);
		ClapTrap&	operator=(const ClapTrap& src);
					~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
