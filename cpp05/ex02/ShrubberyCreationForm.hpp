#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		                       ShrubberyCreationForm();
		                       ShrubberyCreationForm(std::string name, bool is_signed, std::string target);
		                       ~ShrubberyCreationForm();
		                       ShrubberyCreationForm(const ShrubberyCreationForm & obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		void                   execute(Bureaucrat const & executor) const;

	private:
		std::string            _target;
};

#endif  // SHRUBBERYCREATIONFORM_HPP_
