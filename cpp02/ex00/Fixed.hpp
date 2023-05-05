/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:31:39 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 20:31:41 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
				Fixed();
				Fixed(Fixed const& original);
				Fixed&	operator=(Fixed const& original);
				~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static int const	_fractionalBits = 8;
};

#endif
