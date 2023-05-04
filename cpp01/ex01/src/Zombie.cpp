/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:36 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 18:11:21 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombie class
#include <iostream> // cout

Zombie::Zombie(void)
{
	std::cout << "Unnamed Zombie default constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout
	<< this->name
	<< " constructor called."
	<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout
	<< this->name << " destructor called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout
	<< this->name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
