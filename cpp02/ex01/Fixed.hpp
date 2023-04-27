
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
