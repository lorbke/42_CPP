/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:31:29 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 19:46:15 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
				Fixed();
				Fixed(Fixed const& original);
				Fixed(int const raw);
				Fixed(float const raw);
		Fixed&	operator=(Fixed const& original);
				~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& out, Fixed const& fixed);

#endif
