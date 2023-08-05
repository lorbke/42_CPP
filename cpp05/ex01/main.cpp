#include "Bureaucrat.hpp"
#include <iostream>

void test_one() {
    std::cout << "test one:" << std::endl;

    Form f;
    try {
        f = Form("Passierschein A38", false, 150, 151);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_two() {
    std::cout << "test two:" << std::endl;

    Form f;
    try {
        f = Form("Passierschein A38", false, 151, 150);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_three() {
    std::cout << "test three:" << std::endl;

    Form f;
    try {
        f = Form("Passierschein A38", false, 1, 0);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_four() {
    std::cout << "test four:" << std::endl;

    Form f;
    try {
        f = Form("Passierschein A38", false, 0, 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_five() {
    std::cout << "test five:" << std::endl;

    Bureaucrat b("Manfred", 3);
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << "Incrementing grade..." << std::endl;
    std::cout << b << std::endl;
}

void test_six() {
    std::cout << "test six:" << std::endl;

    Form f("Passierschein A38", false, 1, 1);
    std::cout << f << std::endl;
}

void test_seven() {
    std::cout << "test seven:" << std::endl;

    Bureaucrat b("Manfred", 10);
    Form f("Passierschein A38", false, 10, 1);
    std::cout << f.getIsSigned() << std::endl;
    try {
        f.beSigned(b);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << f.getIsSigned() << std::endl;
}

void test_eight() {
    std::cout << "test eight:" << std::endl;

    Bureaucrat b("Manfred", 2);
    Form f("Passierschein A38", false, 1, 1);
    try {
        b.signForm(f);
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
    test_five();
    test_six();
    test_seven();
    test_eight();

    return 0;
}