
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
		Animal&		operator=(const Animal& src);
		virtual		~Animal();
		std::string	getType() const;
		void		makeSound() const;
	protected:
					Animal();
					Animal(const Animal& src);
		std::string	_type;
};

#endif
