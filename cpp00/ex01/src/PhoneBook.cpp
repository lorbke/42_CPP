/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:52:59 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/01 21:26:32 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook()
{
	_count = 0;
	_max_contacts = 8;
}

int	PhoneBook::get_max_contacts(void)
{
	return (_max_contacts);
}

void	PhoneBook::add_contact(Contact contact)
{
	if (_count >= _max_contacts)
		_contacts[_count % _max_contacts] = contact;
	else
		_contacts[_count] = contact;
	_count++;
}

Contact	PhoneBook::get_contact(const int index)
{
	return (_contacts[index]);
}
