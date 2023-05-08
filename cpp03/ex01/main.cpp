/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:20:53 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 14:44:47 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

int	main(void)
{
	ScavTrap	Bill("Bill");
	ScavTrap	Bob("Bob");

	std::cout << std::endl 
	<< GREEN "member functions test:" RESET << std::endl;
	Bill.attack("Bob");
	Bob.takeDamage(1);
	Bob.beRepaired(1);

	std::cout << std::endl
	<< GREEN "no health test:" RESET << std::endl;
	Bill.takeDamage(100);
	Bill.takeDamage(1);

	std::cout << std::endl
	<< GREEN "no energy test:" RESET << std::endl;
	for (int i = 0; i < 51; i++)
		Bob.attack("Bill");

	std::cout << std::endl
	<< GREEN "guardGate test:" RESET << std::endl;
	Bill.guardGate();

	std::cout << std::endl;
	return (0);
}
