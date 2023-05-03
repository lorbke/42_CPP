/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:47 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:09:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		const std::string&	getType(void);
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif
