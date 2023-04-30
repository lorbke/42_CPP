
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
					Animal();
					Animal(const Animal& src);
		Animal&		operator=(const Animal& src);
				 	~Animal();
		std::string	getType() const;
		void		makeSound() const;
	protected:
		std::string	_type;
};

#endif
