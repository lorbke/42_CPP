/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:57:29 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 18:24:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

int	main(void)
{
	DiamondTrap	Steve("Steve");
	DiamondTrap	Stewie("Stewie");

	std::cout << std::endl 
	<< GREEN "member functions test:" RESET << std::endl;
	Steve.attack("Tom");
	Stewie.takeDamage(1);
	Stewie.beRepaired(1);

	std::cout << std::endl
	<< GREEN "no health test:" RESET << std::endl;
	Steve.takeDamage(100);
	Steve.takeDamage(1);

	std::cout << std::endl
	<< GREEN "no energy test:" RESET << std::endl;
	for (int i = 0; i < 50; i++)
		Stewie.attack("Steve");

	std::cout << std::endl
	<< GREEN "whoAmI test:" RESET << std::endl;
	Steve.whoAmI();

	std::cout << std::endl;
	return (0);
}