#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void test_one() {
    std::cout << "test one:" << std::endl;

    Intern i = Intern();

    AForm* f = i.makeForm("shrubbery creation", "home");
    if (f) {
        std::cout << *f << std::endl;
        delete f;
    }
}

void test_two() {
    std::cout << "test two:" << std::endl;

    Intern i = Intern();

    AForm* f = i.makeForm("request", "home");
    if (f) {
        std::cout << *f << std::endl;
        delete f;
    }
}

int main(void) {
    test_one();
    test_two();

    return 0;
}