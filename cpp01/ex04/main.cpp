/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:50 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/04 21:48:56 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream> // read and write on files
#include <cstdlib> // EXIT_* defines

void	search_and_replace(std::ifstream& file_in, std::ofstream& file_out,
		const std::string search, const std::string replace)
{
	std::string	buffer;
	int			j = 0;

	while (std::getline(file_in, buffer))
	{
		if (j != 0)
			file_out << std::endl;
		for (unsigned int i = 0; i < buffer.length(); i++)
		{
			if (i == buffer.find(search))
			{
				buffer.erase(buffer.begin(), buffer.begin() + i + search.length());
				i = 0;
				file_out << replace;
			}
			file_out << buffer[i];
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout
		<< "Usage: ./search_and_replace <filename> <str to search> <str to replace>"
		<< std::endl;
		return (EXIT_FAILURE);
	}

	std::ifstream	file_in;
	std::ofstream	file_out;
	std::string		file_out_name = (std::string)argv[1] + ".replace";
	file_in.open(argv[1]);
	file_out.open(file_out_name.c_str());
	if (file_in.is_open() == false || file_out.is_open() == false)
	{
		std::cerr << "Can't open files!" << std::endl;
		return (EXIT_FAILURE);
	}

	search_and_replace(file_in, file_out, argv[2], argv[3]);
	return (EXIT_SUCCESS);
}
