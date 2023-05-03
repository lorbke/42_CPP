/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:08:22 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:08:29 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

enum	Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./complain [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (EXIT_FAILURE);
	}

	Harl 	harl;
	harl.complain(argv[1]);

	return (EXIT_SUCCESS);
}
