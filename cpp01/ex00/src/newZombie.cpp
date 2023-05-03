/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:50 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:08:51 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class
#include <string> // string

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie = new Zombie(name);
	return (zombie);
}
