/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:30 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 18:21:32 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Tim("Tim");
	ClapTrap	Tom("Tom");

	Tim.attack("Tom");
	Tom.takeDamage(1);
	Tom.beRepaired(1);
	return (0);
}
