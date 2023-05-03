/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:25 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:27 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class	HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon&		weapon;
};

#endif
