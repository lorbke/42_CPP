
#include "Weapon.hpp"
#include <string>

class	HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon*		weapon;
};
