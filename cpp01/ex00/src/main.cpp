/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:46 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:08:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class

int	main(void)
{
	Zombie*	zombie = newZombie("Seppel");
	zombie->announce();

	randomChump("Gertrud");
	randomChump("Hans");

	delete zombie;
	return (0);
}
