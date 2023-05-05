/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:26:37 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/05 20:26:38 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
						Fixed();
						Fixed(Fixed const& original);
						Fixed(int const raw);
						Fixed(float const raw);
		Fixed&			operator=(Fixed const& original);
		bool			operator>(Fixed const& other);
		bool			operator<(Fixed const& other);
		bool			operator>=(Fixed const& other);
		bool			operator<=(Fixed const& other);
		bool			operator==(Fixed const& other);
		bool			operator!=(Fixed const& other);
		Fixed&			operator+(Fixed const& addend);
		Fixed&			operator-(Fixed const& subtrahend);
		Fixed&			operator*(Fixed const& multiplier);
		Fixed&			operator/(Fixed const& divisor);
		Fixed&			operator++(void);
		Fixed			operator++(int postfix __attribute__ ((unused)));
		Fixed&			operator--(void);
		Fixed			operator--(int postfix __attribute__ ((unused)));
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	min(Fixed const& a, Fixed const& b);
		static Fixed&	max(Fixed const& a, Fixed const& b);
						~Fixed();
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

	private:
		int					_value;
		static int const	_fractionalBits = 8;
};

#endif