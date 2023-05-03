/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:33 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:35 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class	HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon*		weapon;
};

#endif
