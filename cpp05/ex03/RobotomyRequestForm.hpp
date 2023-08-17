#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	public:
		                       RobotomyRequestForm();
		                       RobotomyRequestForm(std::string name, bool is_signed, std::string target);
		                       ~RobotomyRequestForm();
		                       RobotomyRequestForm(const RobotomyRequestForm & obj);
		RobotomyRequestForm&   operator=(const RobotomyRequestForm& obj);
		void                   execute(Bureaucrat const & executor) const;

	private:
		std::string            _target;
};

#endif  // RobotomyRequestForm_HPP_
