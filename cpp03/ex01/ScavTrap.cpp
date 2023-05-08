/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:08 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 17:41:28 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

#define HEALTH 100
#define ENERGY 50
#define ATTACK 20

static bool	check_health(const std::string& name, int health)
{
	if (health <= 0)
	{
		std::cout << "ScavTrap "
		<< name
		<< " has no health left!"
		<< std::endl;
		return (false);
	}
	return (true);
}

static bool	check_energy(const std::string& name, int energy)
{
	if (energy <= 0)
	{
		std::cout << "ScavTrap "
		<< name
		<< " has no energy left!"
		<< std::endl;
		return (false);
	}
	return (true);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been created!" << std::endl;
	this->_hitPoints = HEALTH;
	this->_energyPoints = ENERGY;
	this->_attackDamage = ATTACK;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been created as a copy from"
	<< src._name
	<< "!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " has been assigned a copy of "
	<< src._name
	<< "!" << std::endl;
	ClapTrap::operator=(src);
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
	if (!check_energy(this->_name, this->_energyPoints)
		|| !check_health(this->_name, this->_hitPoints))
		return ;
	this->_energyPoints--;
	std::cout << "ScavTrap "
	<< this->_name
	<< " attacks "
	<< target
	<< ", causing "
	<< this->_attackDamage
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap "
	<< this->_name
	<< " is now in Gate keeper mode." << std::endl;
}
