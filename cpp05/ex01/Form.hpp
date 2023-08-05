#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
	public:
		            Form();
		            Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_exec);
		            ~Form();
		            Form(const Form & obj);
		Form&       operator=(const Form& obj);
		std::string getName() const;
		bool        getIsSigned() const;
		int         getGradeToSign() const;
		int         getGradeToExec() const;
		void        beSigned(const Bureaucrat& b);

	protected:
		class GradeTooLowException : public std::exception {
			const char * what () const throw () {
				return "Grade cannot be below 150";
			}
		};
		class GradeTooHighException : public std::exception {
			const char * what () const throw () {
				return "Grade cannot be above 1";
			}
		};

	private:
		const std::string _name;
		bool              _is_signed;
		const int         _grade_to_sign;
		const int         _grade_to_exec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP_
