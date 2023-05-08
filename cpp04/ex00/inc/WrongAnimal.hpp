
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class	WrongAnimal
{
	public:
						WrongAnimal();
						WrongAnimal(const WrongAnimal& src);
		WrongAnimal&	operator=(const WrongAnimal& src);
		virtual 		~WrongAnimal();
		std::string		getType() const;
		virtual void	makeSound() const;
	protected:
		std::string	_type;
};

#endif
