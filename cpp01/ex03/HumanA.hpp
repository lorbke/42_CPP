
#include "Weapon.hpp"
#include <string>

class	HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon&		weapon;
};
