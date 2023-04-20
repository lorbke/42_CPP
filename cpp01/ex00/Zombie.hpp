
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* __________________________________________________________________INCLUDES */


# include <string> // string

/* ______________________________________________________________ZOMBIE CLASS */

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:
		std::string	name;
};

/* _________________________________________________________________FUNCTIONS */

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
