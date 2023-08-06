#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

#define FORM_NUM 3

const std::string formNames[FORM_NUM] = {
  "shrubbery creation",
  "robotomy request",
  "presidential pardon"
};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern & obj) { *this = obj; }

Intern& Intern::operator=(const Intern& obj) {
  (void)obj;
  return *this;
}

AForm* makeShrubberyCreationForm(const std::string& name, const std::string& target) {
  return new ShrubberyCreationForm(name, false, target);
}

AForm* makeRobotomyRequestForm(const std::string& name, const std::string& target) {
  return new RobotomyRequestForm(name, false, target);
}

AForm* makePresidentialPardonForm(const std::string& name, const std::string& target) {
  return new PresidentialPardonForm(name, false, target);
}

typedef AForm* (*formFunc)(const std::string&, const std::string&);

const formFunc formFuncs[FORM_NUM] = {
  &makeShrubberyCreationForm,
  &makeRobotomyRequestForm,
  &makePresidentialPardonForm
};

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
	for (int i = 0; i < FORM_NUM; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (formFuncs[i])(name, target);
		}
		else {
			std::cout << "ehm...what is an " << name << "?" << std::endl;
			return NULL;
		}
	}
	return NULL;
}
