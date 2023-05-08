/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:40:57 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 18:47:39 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

#define HEALTH 100
#define ENERGY 100
#define DAMAGE 30

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap "
	<< this->_name
	<< " has been created!" << std::endl;
	this->_hitPoints = HEALTH;
	this->_energyPoints = ENERGY;
	this->_attackDamage = DAMAGE;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap "
	<< this->_name
	<< " has been created!" << std::endl;
	this->_hitPoints = HEALTH;
	this->_energyPoints = ENERGY;
	this->_attackDamage = DAMAGE;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap "
	<< this->_name
	<< " has been created as a copy from"
	<< src._name
	<< "!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap "
	<< this->_name
	<< " has been assigned a copy of "
	<< src._name
	<< "!" << std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "
	<< this->_name
	<< " has been destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "
	<< this->_name
	<< " is requesting a high five, guys!" << std::endl;
}
