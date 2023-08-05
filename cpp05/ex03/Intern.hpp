#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  ~Intern();
  Intern(const Intern & obj);
  Intern& operator=(const Intern& obj);
  AForm* makeForm(const std::string& name, const std::string& target) const;

 private:
};

#endif  // INTERN_HPP_
