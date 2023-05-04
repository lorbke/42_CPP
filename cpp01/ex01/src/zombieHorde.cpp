/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:42 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 18:15:52 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 0)
		return (NULL);

	Zombie*	zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);

	return (zombies);
}
