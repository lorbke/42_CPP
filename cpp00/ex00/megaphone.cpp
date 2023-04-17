/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:16:51 by lorbke            #+#    #+#             */
/*   Updated: 2023/04/17 18:45:20 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // input/output operations
#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE

#define EMPTY_ARG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
	{
		std::cout << EMPTY_ARG << std::endl;
		return (EXIT_SUCCESS);
	}
	str = argv[1];
	for (uint i = 0; i < str.length(); i++)
		std::cout << (char)toupper(str[i]);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
