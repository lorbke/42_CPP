/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:39 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:08:41 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
