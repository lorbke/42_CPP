
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
						Animal();
						Animal(const Animal& src);
		Animal&			operator=(const Animal& src);
		virtual			~Animal();
		std::string		getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string	_type;
};

#endif
