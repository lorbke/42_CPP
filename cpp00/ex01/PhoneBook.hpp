
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* _________________________________________________________________ INCLUDES */

# include "Contact.hpp"

/* ____________________________________________________________________ CLASS */

class	PhoneBook
{
	public:
		PhoneBook();
		void	add_contact(Contact contact, const int index);
		Contact	get_contact(const int index);
		int		get_count(void);

	private:	
		Contact	_contacts[8];
		int		count;
};

#endif
