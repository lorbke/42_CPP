/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:40:49 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 14:43:35 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

int	main(void)
{
	FragTrap	Jill("Jill");
	FragTrap	Jane("Jane");

	std::cout << std::endl 
	<< GREEN "member functions test:" RESET << std::endl;
	Jill.attack("Tom");
	Jane.takeDamage(1);
	Jane.beRepaired(1);

	std::cout << std::endl
	<< GREEN "no health test:" RESET << std::endl;
	Jill.takeDamage(100);
	Jill.takeDamage(1);

	std::cout << std::endl
	<< GREEN "no energy test:" RESET << std::endl;
	for (int i = 0; i < 101; i++)
		Jane.attack("Jill");

	std::cout << std::endl
	<< GREEN "highFivesGuys test:" RESET << std::endl;
	Jill.highFivesGuys();

	std::cout << std::endl;
	return (0);
}