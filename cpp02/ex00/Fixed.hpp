
#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& original);
		Fixed&	operator=(const Fixed& original);
		~Fixed();
		int	getRawBits(void) const;
		void		setRawBits(const int raw);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

#endif
