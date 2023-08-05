#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <sstream>

class Bureaucrat;

class AForm {
	public:
		             AForm();
		             AForm(std::string name, bool is_signed, int grade_to_sign, int grade_to_exec);
		             ~AForm();
		             AForm(const AForm & obj);
		AForm&       operator=(const AForm& obj);
		std::string  getName() const;
		bool         getIsSigned() const;
		int          getGradeToSign() const;
		int          getGradeToExec() const;
		void         beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0; // pure virtual function

	protected:
		class GradeTooLowException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooLowException() {
					_message = "grade cannot be below 1";
				}
				GradeTooLowException(int grade) {
					std::ostringstream oss;
					oss << "grade cannot be below " << grade;
					_message = oss.str();
				}

				const char* what() const throw() {
					return _message.c_str();
				}
				~GradeTooLowException() throw() {}
		};
		class GradeTooHighException : public std::exception {
			private:
				std::string _message;

			public:
				GradeTooHighException() {
					_message = "grade cannot be above 150";
				}
				GradeTooHighException(int grade) {
					std::ostringstream oss;
					oss << "grade cannot be above " << grade;
					_message = oss.str();
				}

				const char* what() const throw() {
					return _message.c_str();
				}
				~GradeTooHighException() throw() {}
		};
		class FormNotSignedException : public std::exception {
			const char* what() const throw() {
				return "form is not signed";
			}
		};
	private:
		const std::string _name;
		bool              _is_signed;
		const int         _grade_to_sign;
		const int         _grade_to_exec;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // FORM_HPP_
