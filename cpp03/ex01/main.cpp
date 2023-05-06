/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:20:53 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 18:25:15 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Tim("Tim");
	ClapTrap	Tom("Tom");
	Tim.attack("Tom");
	Tom.takeDamage(1);
	Tom.beRepaired(1);

	ScavTrap	Jim("Jim");
	ScavTrap	Jack("Jack");
	Jim.attack("Jack");
	Jack.takeDamage(1);
	Jack.beRepaired(1);
	Jim.guardGate();
	return (0);
}
