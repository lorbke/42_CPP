/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:08 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/07 18:36:34 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been created!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been created as a copy from"
	<< src.getName()
	<< "!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	ClapTrap::operator=(src);
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been assigned a copy of "
	<< src.getName()
	<< "!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0)
		return ;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap "
	<< this->_name
	<< " attacks "
	<< target
	<< ", causing "
	<< this->getAttackDamage()
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " is now in Gate keeper mode." << std::endl;
}
