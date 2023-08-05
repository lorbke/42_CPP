#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

#define GRADE_MIN 1
#define GRADE_MAX 150

Bureaucrat::Bureaucrat() : _name("default"), _grade(GRADE_MAX) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (_grade > GRADE_MAX)
        throw GradeTooLowException();
    if (_grade < GRADE_MIN)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat & obj) { *this = obj; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
    (void)obj;
    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= GRADE_MIN)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= GRADE_MAX)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}