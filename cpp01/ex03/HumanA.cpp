/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:22 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:23 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout
	<< this->name
	<< " attacks with their "
	<< this->weapon.getType()
	<< std::endl;
}
