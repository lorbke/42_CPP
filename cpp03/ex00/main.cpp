/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:30 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/07 18:34:21 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

int	main(void)
{
	ClapTrap	Tim("Tim");
	ClapTrap	Tom("Tom");

	std::cout << std::endl 
	<< GREEN <<  "member functions test:" RESET << std::endl;
	Tim.attack("Tom");
	Tom.takeDamage(1);
	Tom.beRepaired(1);

	std::cout << std::endl
	<< GREEN << "no health test:" <<  RESET << std::endl;
	Tim.takeDamage(10);
	Tim.takeDamage(1);

	std::cout << std::endl
	<< GREEN << "no energy test:" RESET << std::endl;
	for (int i = 0; i < 10; i++)
		Tom.attack("Tim");

	std::cout << std::endl;
	return (0);
}
