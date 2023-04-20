
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* __________________________________________________________________INCLUDES */


# include <string> // string

/* ______________________________________________________________ZOMBIE CLASS */

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	name;
};

/* _________________________________________________________________FUNCTIONS */

Zombie*	zombieHorde( int N, std::string name );

#endif
