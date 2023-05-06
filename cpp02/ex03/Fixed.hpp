/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:31:17 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/06 22:15:26 by lorbke           ###   ########.fr       */
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
		Fixed&				operator=(Fixed const& original);
		bool				operator>(Fixed const& other) const;
		bool				operator<(Fixed const& other) const;
		bool				operator>=(Fixed const& other) const;
		bool				operator<=(Fixed const& other) const;
		bool				operator==(Fixed const& other) const;
		bool				operator!=(Fixed const& other) const;
		Fixed				operator+(Fixed const& addend) const;
		Fixed				operator-(Fixed const& subtrahend) const;
		Fixed				operator*(Fixed const& multiplier) const;
		Fixed				operator/(Fixed const& divisor) const;
		Fixed&				operator++(void);
		Fixed				operator++(int postfix __attribute__ ((unused)));
		Fixed&				operator--(void);
		Fixed				operator--(int postfix __attribute__ ((unused)));
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);
							~Fixed();
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					_value;
		static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
