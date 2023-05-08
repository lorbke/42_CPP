/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:40:53 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 17:27:06 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
					FragTrap(std::string name);
					FragTrap(const FragTrap& src);
		FragTrap&	operator=(const FragTrap& src);
					~FragTrap();
		void		highFivesGuys(void);
	private:
};

#endif
