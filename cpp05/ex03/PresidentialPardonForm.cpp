#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string name, bool is_signed, std::string target) :
	AForm(name, is_signed, 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & obj) :
	AForm(this->getName(), this->getIsSigned(), this->getGradeToSign(), this->getGradeToExec()) {
		*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	(void)obj;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException(this->getGradeToExec());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
