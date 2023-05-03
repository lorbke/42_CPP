/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:09:59 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/02 15:10:01 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	public:
		void	complain(std::string level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
