/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:01 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class
#include <iostream> // cout

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout
	<< this->name
	<< " died."
	<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout
	<< this->name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}
