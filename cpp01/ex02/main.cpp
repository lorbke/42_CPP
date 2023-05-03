/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:15 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:19 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";

	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
