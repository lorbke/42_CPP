#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string name, bool is_signed, std::string target) :
	AForm(name, is_signed, 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & obj) :
	AForm(this->getName(), this->getIsSigned(), this->getGradeToSign(), this->getGradeToExec()) {
		*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this != &obj)
		_target = obj._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException(this->getGradeToExec());
	std::cout << "* drilling noises *" << std::endl;
	srand(time(NULL)); // create new seed from current time for rand()
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << "'s robotomization failed" << std::endl;
}
