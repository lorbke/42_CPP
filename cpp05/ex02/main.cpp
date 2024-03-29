#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void test_one() {
    std::cout << "test one:" << std::endl;

    Bureaucrat b("b", 146);
    ShrubberyCreationForm f("f", false, "Hotblack Desiato");

    try {
        b.signForm(f);
        f.execute(b);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_two() {
    std::cout << "test two:" << std::endl;

    Bureaucrat b("b", 45);
    RobotomyRequestForm f("f", false, "Marvin");

    try {
        b.signForm(f);
        f.execute(b);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_three() {
    std::cout << "test three:" << std::endl;

    Bureaucrat b("b", 5);
    PresidentialPardonForm f("f", false, "Arthur Dent");

    try {
        b.signForm(f);
        f.execute(b);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_four() {
    std::cout << "test four:" << std::endl;

    Bureaucrat b("b", 5);
    PresidentialPardonForm f("f", false, "Hotblack Desiato");

    try {
        b.signForm(f);
        b.executeForm(f);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(void) {
    test_one();
    test_two();
    test_three();
    test_four();

    return 0;
}