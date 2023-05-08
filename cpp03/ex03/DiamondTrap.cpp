/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:57:38 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 18:23:18 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
	_name(name)
{
	ScavTrap	temp_scav(name);

	this->ClapTrap::_energyPoints = temp_scav.ScavTrap::getEnergyPoints();
	std::cout << "DiamondTrap "
	<< this->_name
	<< " has been created!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &src)
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " has been assigned a copy of "
	<< src._name
	<< "!" << std::endl;
	this->_name = src._name;
	ClapTrap::operator=(src);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " has been destroyed!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " is "
	<< this->ClapTrap::_name
	<< "!" << std::endl;
}
