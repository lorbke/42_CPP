#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	public:
		                        PresidentialPardonForm();
		                        PresidentialPardonForm(std::string name, bool is_signed, std::string target);
		                        ~PresidentialPardonForm();
		                        PresidentialPardonForm(const PresidentialPardonForm & obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		void                    execute(Bureaucrat const & executor) const;

	private:
		std::string             _target;
};

#endif  // PresidentialPardonForm_HPP_
