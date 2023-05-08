/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:57:44 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/08 17:20:14 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
						DiamondTrap(std::string name);
						~DiamondTrap();
		DiamondTrap&	operator=(DiamondTrap const &src);
		using			ScavTrap::attack;
		void			whoAmI();
	private:
		std::string _name;
};

#endif
