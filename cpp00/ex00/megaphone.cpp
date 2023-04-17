/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:16:51 by lorbke            #+#    #+#             */
/*   Updated: 2023/04/17 22:00:43 by lorbke           ###   ########.fr       */
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
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (uint j = 0; j < str.length(); j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
