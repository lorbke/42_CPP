#include "Bureaucrat.hpp"
#include <iostream>

void test_one() {
    std::cout << "test one:" << std::endl;

    Bureaucrat b;
    try {
        b = Bureaucrat("Manfred", 0);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_two() {
    std::cout << "test two:" << std::endl;

    Bureaucrat b;
    try {
        b = Bureaucrat("Manfred", 151);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_three() {
    std::cout << "test three:" << std::endl;

    Bureaucrat b;
    try {
        b = Bureaucrat("Manfred", 150);
        b.decrementGrade();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void test_four() {
    std::cout << "test four:" << std::endl;

    Bureaucrat b;
    try {
        b = Bureaucrat("Manfred", 1);
        b.incrementGrade();
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

    Bureaucrat b("Manfred", 3);
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << "Decrementing grade..." << std::endl;
    std::cout << b << std::endl;
}

void test_seven() {
    std::cout << "test seven:" << std::endl;

    Bureaucrat b("Manfred", 111);
    std::cout << b << std::endl;
}

int main() {
    test_one();
    test_two();
    test_three();
    test_four();
    test_five();
    test_six();
    test_seven();

    return 0;
}