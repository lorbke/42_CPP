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
    std::cout << *f << std::endl;
    // try {
    //     b.signForm(f);
    //     f.execute(b);
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
}

void test_two() {
    std::cout << "test two:" << std::endl;

    Intern i = Intern();

    AForm* f = i.makeForm("request", "home");
    std::cout << *f << std::endl;
    // try {
    //     b.signForm(f);
    //     f.execute(b);
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
}

// @todo replace with fixed files from ex02 if changes were made
// @todo understand function pointer array syntax better
// @todo do an exception instead of regular error?
// @todo check leaks

int main(void) {
    test_one();
    test_two();
    // test_three();
    // test_four();
    // test_five();
    // test_six();
    // test_seven();
    // test_eight();

    return 0;
}