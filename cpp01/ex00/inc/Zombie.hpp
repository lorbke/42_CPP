/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:05 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 18:11:49 by lorbke           ###   ########.fr       */
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

	private:
		std::string	name;
};

/* _________________________________________________________________FUNCTIONS */

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
