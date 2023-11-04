#include "Form.hpp"

#include <string>
#include <iostream>

#define GRADE_MIN 1
#define GRADE_MAX 150

Form::Form() : _name("default"), _is_signed(false), _grade_to_sign(GRADE_MAX), _grade_to_exec(GRADE_MAX) {}

Form::Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_exec) :
	_name(name), _is_signed(is_signed), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
	if (grade_to_sign < GRADE_MIN || grade_to_exec < GRADE_MIN)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > GRADE_MAX || grade_to_exec > GRADE_MAX)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form & obj) : _name(obj._name), _is_signed(obj._is_signed), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec) {
	*this = obj;
}

Form& Form::operator=(const Form& obj) {
	if (this != &obj)
		_is_signed = obj._is_signed;
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getGradeToSign() const {
	return _grade_to_sign;
}

int Form::getGradeToExec() const {
	return _grade_to_exec;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", is signed: " << f.getIsSigned()
	<< ", grade required to sign: " << f.getGradeToSign()
	<< ", grade required to execute: " << f.getGradeToExec();
    return os;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}