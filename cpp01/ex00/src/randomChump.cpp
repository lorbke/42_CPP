/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:53 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:08:55 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class

void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
}
