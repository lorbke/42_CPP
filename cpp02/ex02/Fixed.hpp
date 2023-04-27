
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& original);
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed&	operator=(const Fixed& original);
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator==(const Fixed& other);
		bool	operator!=(const Fixed& other);
		Fixed&	operator+(const Fixed& addend);
		Fixed&	operator-(const Fixed& subtrahend);
		Fixed&	operator*(const Fixed& multiplier);
		Fixed&	operator/(const Fixed& divisor);
		Fixed&	operator++(void);
		Fixed	operator++(int postfix __attribute__ ((unused)));
		Fixed&	operator--(void);
		Fixed	operator--(int postfix __attribute__ ((unused)));
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(const Fixed& a, const Fixed& b);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

#endif
