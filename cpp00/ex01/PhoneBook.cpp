
#include "PhoneBook.hpp"
#include <iostream>

// @todo remove this
PhoneBook::PhoneBook()
{
	// _contacts[0].first_name = "John";
	// _contacts[0].last_name = "Doe";
	// _contacts[0].nickname = "JD";
	// _contacts[0].phone_number = "1234567890";
	// _contacts[1].first_name = "Jane";
	// _contacts[1].last_name = "Doe";
	// _contacts[1].nickname = "JD";
	// _contacts[1].phone_number = "1234567890";
	// _contacts[2].first_name = "Tim";
	// _contacts[2].last_name = "Honnef";
	// _contacts[2].nickname = "TH";
	// _contacts[2].phone_number = "1234567890";
	// _contacts[3].first_name = "Tim";
	// _contacts[3].last_name = "Honnef";
	// _contacts[3].nickname = "TH";
	// _contacts[3].phone_number = "1234567890";
	// _contacts[4].first_name = "Tim";
	// _contacts[4].last_name = "Honnef";
	// _contacts[4].nickname = "TH";
	// _contacts[4].phone_number = "1234567890";
	// _contacts[5].first_name = "Tim";
	// _contacts[5].last_name = "Honnef";
	// _contacts[5].nickname = "TH";
	// _contacts[5].phone_number = "1234567890";
	// _contacts[6].first_name = "Tim";
	// _contacts[6].last_name = "Honnef";
	// _contacts[6].nickname = "TH";
	// _contacts[6].phone_number = "1234567890";
	// _contacts[7].first_name = "Tim";
	// _contacts[7].last_name = "Honnef";
	// _contacts[7].nickname = "TH";
	// _contacts[7].phone_number = "1234567890";
	count = 0;
}

int	PhoneBook::get_count(void)
{
	return (count);
}

void	PhoneBook::add_contact(Contact contact, const int index)
{
	if (index > 7)
	{
		_contacts[index % 7] = contact;
		count = 8;
	}
	else
	{
		_contacts[index] = contact;
		count++;
	}
}

Contact	PhoneBook::get_contact(const int index)
{
	return (_contacts[index]);
}
