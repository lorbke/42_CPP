/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:22 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 21:34:26 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	std::cout << "HumanA constructor called" << std::endl;
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout
	<< this->name
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}
