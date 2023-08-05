#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

#define GRADE_MIN 1
#define GRADE_MAX 150

Bureaucrat::Bureaucrat() : _name("default"), _grade(GRADE_MAX) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (_grade >= GRADE_MAX)
        throw GradeTooHighException();
    if (_grade <= GRADE_MIN)
        throw GradeTooLowException();
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
        throw GradeTooLowException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= GRADE_MAX)
        throw GradeTooHighException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}