/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:20:58 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 18:20:59 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
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
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		return ;
	this->_energyPoints--;
	std::cout << "ClapTrap "
	<< this->_name
	<< " has gained "
	<< amount
	<< " hit points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
		return ;
	this->_hitPoints -= amount;
	std::cout << "ClapTrap "
	<< this->_name
	<< " has lost "
	<< amount
	<< " hit points!" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName(const std::string& name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}
