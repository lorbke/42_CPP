/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:32 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 18:18:34 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class

int	main(void)
{
	int	count = 5;
	Zombie*	zombies = zombieHorde(count, "Bob");

	for (int i = 0; i < count; i++)
		zombies[i].announce();
	
	// [] necessary because zombies refers to an array of objects
	delete [] zombies;

	return (0);
}
