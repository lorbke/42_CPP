/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:23 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 18:46:32 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define HEALTH 10
#define ENERGY 10
#define ATTACK 0

static bool	check_health(const std::string& name, int health)
{
	if (health <= 0)
	{
		std::cout << "ClapTrap "
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
		std::cout << "ClapTrap "
		<< name
		<< " has no energy left!"
		<< std::endl;
		return (false);
	}
	return (true);
}

ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(HEALTH),
	_energyPoints(ENERGY), _attackDamage(ATTACK)
{
	std::cout << "ClapTrap "
	<< this->_name
	<< " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(HEALTH), _energyPoints(ENERGY), _attackDamage(ATTACK)
{
	std::cout << "ClapTrap "
	<< this->_name
	<< " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
	: _name(src._name), _hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap "
	<< this->_name
	<< " has been created as a copy from "
	<< src._name
	<< "!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "
	<< this->_name
	<< " has been destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!check_energy(this->_name, this->_energyPoints)
		|| !check_health(this->_name, this->_hitPoints))
		return ;
	this->_energyPoints--;
	std::cout << "ClapTrap "
	<< this->_name
	<< " attacks "
	<< target
	<< ", causing "
	<< this->_attackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!check_energy(this->_name, this->_energyPoints)
		|| !check_health(this->_name, this->_hitPoints))
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap "
	<< this->_name
	<< " has gained "
	<< amount
	<< " hit points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!check_health(this->_name, this->_hitPoints))
		return ;
	this->_hitPoints -= amount;
	std::cout << "ClapTrap "
	<< this->_name
	<< " has lost "
	<< amount
	<< " hit points!" << std::endl;
}
