#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, bool is_signed, std::string target) :
	AForm(name, is_signed, 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & obj) :
	AForm(this->getName(), this->getIsSigned(), this->getGradeToSign(), this->getGradeToExec()) {
		*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	(void)obj;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException(this->getGradeToExec());
	std::string filename = _target + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	file << "       # #### ####" << std::endl;
	file << "     ### \\/#|### |/####" << std::endl;
	file << "   ##\\/#/ \\||/##/_/##/_#" << std::endl;
	file << " ###  \\/###|/ \\/ # ###" << std::endl;
	file << "##_\\_#\\_\\## | #/###_/_####" << std::endl;
	file << "## #### # \\ #| /  #### ##/##" << std::endl;
	file << " __#_--###`  |{,###---###-~" << std::endl;
	file << "           \\ }{" << std::endl;
	file << "            }}{" << std::endl;
	file << "            }}{" << std::endl;
	file << "            {{}" << std::endl;
	file << "      , -=-~{ .-^- _" << std::endl;
	file << "            `}" << std::endl;
	file << "             {" << std::endl;
	file.close();
}
