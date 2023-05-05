
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
