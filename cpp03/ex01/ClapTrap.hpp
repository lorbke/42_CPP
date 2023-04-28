
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
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(const std::string& name);
		void		setHitPoints(int hitPoints);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
