/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:52:47 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/01 17:48:36 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* _________________________________________________________________ INCLUDES */

# include "Contact.hpp"

/* ____________________________________________________________________ CLASS */

class	PhoneBook
{
	public:
				PhoneBook();
		void	add_contact(Contact contact);
		Contact	get_contact(const int index);
		int		get_max_contacts(void);
	private:	
		Contact	_contacts[8];
		int		_count;
		int		_max_contacts;
};

#endif
