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

#define MAX_CONTACTS 2

PhoneBook::PhoneBook()
{
	_count = 0;
}

int	PhoneBook::get_count(void)
{
	return (_count);
}

void	PhoneBook::add_contact(Contact contact)
{
	if (_count >= MAX_CONTACTS)
	{
		_contacts[_count % MAX_CONTACTS] = contact;
	}
	else
	{
		_contacts[_count] = contact;
		_count++;
	}
}

Contact	PhoneBook::get_contact(const int index)
{
	return (_contacts[index]);
}
