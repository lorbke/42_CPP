#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>

class Bureaucrat {
   public:
                    Bureaucrat();
                    ~Bureaucrat();
                    Bureaucrat(const Bureaucrat& obj);
                    Bureaucrat(const std::string& name, int grade); // passed by reference, because good practice for more complex data types
      Bureaucrat&   operator=(const Bureaucrat& obj);
      std::string   getName() const;
      int           getGrade() const;
      void          incrementGrade();
      void          decrementGrade();

   protected:
      class GradeTooHighException : public std::exception {
         const char * what () const throw () {
            return "Grade cannot be above 150";
         }
      };
      class GradeTooLowException : public std::exception {
         const char * what () const throw () {
            return "Grade cannot be below 1";
         }
      };

   private:
      std::string _name;
      int         _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_HPP_