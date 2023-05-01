/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:05:50 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/01 21:29:34 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // for std::strtol

#define WIDTH 54

void	print_decor(const int width, const char fill)
{
	std::cout << std::right << std::setw(width) << std::setfill(fill) << "" << std::endl;
}

void	print_instructions(void)
{
	print_decor(WIDTH, '=');
	std::cout << "PHONEBOOK" << std::endl;
	std::cout << "Enter one of the following commands: ADD, SEARCH, EXIT" << std::endl;
	print_decor(WIDTH, '=');
}

std::string	get_field(const std::string field_name)
{
	std::string	field;

	std::cout << std::setw(14) << std::setfill(' ') << std::left;
	std::cout << field_name << ": ";
	std::cin >> field;
	return (field);
}

Contact	get_new_contact()
{
	Contact	contact;

	print_decor(WIDTH, '-');
	contact.first_name = get_field("First name");
	contact.last_name = get_field("Last name");
	contact.nickname = get_field("Nickname");
	contact.phone_number = get_field("Phone number");
	contact.darkest_secret = get_field("Darkest secret");
	print_decor(WIDTH, '-');
	return (contact);
}

void	display_string(const std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void	display_contact_short(const Contact contact, const int index)
{
	std::cout << std::setw(10) << std::setfill(' ') << std::right << index << "|";
	display_string(contact.first_name);
	std::cout << "|";
	display_string(contact.last_name);
	std::cout << "|";
	display_string(contact.nickname);
	std::cout << std::endl;
}

void	display_contact_long(const Contact contact)
{
	std::cout << std::endl;
	std::cout << std::right << "Contact details:" << std::endl;
	print_decor(WIDTH, '-');
	std::cout << std::right << "First name    : " << contact.first_name << std::endl;
	std::cout << std::right << "Last name     : " << contact.last_name << std::endl;
	std::cout << std::right << "Nickname      : " << contact.nickname << std::endl;
	std::cout << std::right << "Phone number  : " << contact.phone_number << std::endl;
	std::cout << std::right << "Darkest secret: " << contact.darkest_secret << std::endl;
	print_decor(WIDTH, '-');
}

void	search_function(PhoneBook phonebook)
{
	int	count = phonebook.get_count();

	if (count == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	for (int i = 0; i < count; i++)
	{
		print_decor(WIDTH, '_');
		display_contact_short(phonebook.get_contact(i), i);
	}
	print_decor(WIDTH, '_');

	std::string	str;
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, str);
	char	*endptr = NULL;
	int		index = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0')
		index = -1;
	if (index >= 0 && index < count && str.c_str()[0] != '\0')
		display_contact_long(phonebook.get_contact(index));
	else
		std::cout << "Invalid index" << std::endl;
}

// @todo fix contact overwriting
// @todo switch to ADD and SEARCH commands, max contacts to 8
int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	print_instructions();
	while (1)
	{
		std::getline(std::cin, command);
		if (command == "a")
			phonebook.add_contact(get_new_contact());
		else if (command == "s")
			search_function(phonebook);
		else if (command == "EXIT")
			break ;
		else
			print_instructions();
	}
	return (0);
}
