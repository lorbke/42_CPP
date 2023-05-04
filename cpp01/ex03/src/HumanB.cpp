/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:29 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 21:34:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB constructor called" << std::endl;
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout
	<< this->name
	<< " attacks with their "
	<< this->weapon->getType()
	<< std::endl;
}
