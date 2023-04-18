
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	// contacts[0].first_name = "John";
	// contacts[0].last_name = "Doe";
	// contacts[0].nickname = "JD";
	// contacts[0].phone_number = "1234567890";
	// contacts[1].first_name = "Jane";
	// contacts[1].last_name = "Doe";
	// contacts[1].nickname = "JD";
	// contacts[1].phone_number = "1234567890";
	// contacts[2].first_name = "Tim";
	// contacts[2].last_name = "Honnef";
	// contacts[2].nickname = "TH";
	// contacts[2].phone_number = "1234567890";
	// contacts[3].first_name = "Tim";
	// contacts[3].last_name = "Honnef";
	// contacts[3].nickname = "TH";
	// contacts[3].phone_number = "1234567890";
	// contacts[4].first_name = "Tim";
	// contacts[4].last_name = "Honnef";
	// contacts[4].nickname = "TH";
	// contacts[4].phone_number = "1234567890";
	// contacts[5].first_name = "Tim";
	// contacts[5].last_name = "Honnef";
	// contacts[5].nickname = "TH";
	// contacts[5].phone_number = "1234567890";
	// contacts[6].first_name = "Tim";
	// contacts[6].last_name = "Honnef";
	// contacts[6].nickname = "TH";
	// contacts[6].phone_number = "1234567890";
	// contacts[7].first_name = "Tim";
	// contacts[7].last_name = "Honnef";
	// contacts[7].nickname = "TH";
	// contacts[7].phone_number = "1234567890";
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
		contacts[index % 7] = contact;
		count = 8;
	}
	else
	{
		contacts[index] = contact;
		count++;
	}
}

Contact	PhoneBook::get_contact(const int index)
{
	return (contacts[index]);
}
