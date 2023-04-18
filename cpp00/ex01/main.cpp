
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void	print_instructions(void)
{
	std::cout << "PHONEBOOK" << std::endl;
	std::cout << "Enter one of the following commands: ADD, SEARCH, EXIT" << std::endl;
}

std::string	get_field(std::string field_name)
{
	std::string	field;

	std::cout << field_name << ": ";
	std::cin >> field;
	return (field);
}

Contact	get_new_contact()
{
	Contact	contact;

	contact.first_name = get_field("First name");
	// contact.last_name = get_field("Last name");
	// contact.nickname = get_field("Nickname");
	// contact.phone_number = get_field("Phone number");
	// contact.darkest_secret = get_field("Darkest secret");
	return (contact);
}

void	display_string(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void	display_contact_short(Contact contact, int index)
{
	std::cout << std::setw(10) << std::right << index << "|";
	display_string(contact.first_name);
	std::cout << "|";
	display_string(contact.last_name);
	std::cout << "|";
	display_string(contact.nickname);
	std::cout << std::endl;
}

void	display_contact_long(Contact contact, int index)
{
	std::cout << std::right << "First name: " << contact.first_name << std::endl;
	std::cout << std::right << "Last name: " << contact.last_name << std::endl;
	std::cout << std::right << "Nickname: " << contact.nickname << std::endl;
	std::cout << std::right << "Phone number: " << contact.phone_number << std::endl;
	std::cout << std::right << "Darkest secret: " << contact.darkest_secret << std::endl;
}

void	search_function(PhoneBook phonebook)
{
	int	count = phonebook.get_count();

	for (int i = 0; i < count; i++)
		display_contact_short(phonebook.get_contact(i), i);

	int	index;
	std::cout << "Enter index of contact to display: ";
	std::cin >> index;
	if (index >= 0 && index < count)
		display_contact_long(phonebook.get_contact(index), index);
	else
		std::cout << "Invalid index" << std::endl;
}

// @note ctrl d error
// @todo refactor by understanding std::cout << stuff better
// @todo uncomment all fields
// @todo switch back to ADD and SEARCH instead of a and s
int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	print_instructions();
	int i = 0;
	while (1)
	{
		std::cin >> command;
		if (command == "a")
			phonebook.add_contact(get_new_contact(), i);
		else if (command == "s")
			search_function(phonebook);
		else if (command == "EXIT")
			break ;
		i++;
	}
	return (0);
}
