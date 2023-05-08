/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:21:13 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 18:21:15 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
					ScavTrap(std::string name);
					ScavTrap(const ScavTrap& src);
		ScavTrap&	operator=(const ScavTrap& src);
					~ScavTrap();
		void		guardGate(void);
		void		attack(const std::string& target);
	private:
};

#endif
