#include <iostream>
#include <cstdlib> // strtol
#include <cctype> // isalnum
#include <vector>
#include <cerrno>
#include <climits>
#include "PmergeMe.hpp"

bool is_str_only_num(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void print_vector(std::vector<uint> vec) {
    for(std::vector<uint>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int parse(char **input) {
    std::vector<uint> numbers;

    errno = 0;

    for (int i = 0; input[i]; i++) {
        if (!is_str_only_num(input[i]))
            return 1;
        numbers.push_back(strtol(input[i], NULL, 10));
        if (errno == ERANGE || numbers.back() > INT_MAX)
            return 2;
    }
    // std::cout << "vector:" << std::endl;
    // print_vector(numbers);
    return 0;
}

void print_input(char **argv) {
    for (int i = 0; argv[i]; i++) {
       std::cout << argv[i] << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cerr << "usage: pmergeme { value }" << std::endl;
        return 1;
    }

    switch (parse(++argv))
    {
        case 0:
            std::cout << "success!" << std::endl;
            break;
        case 1:
            std::cerr << "error: wrong input: invalid chars" << std::endl;
            break;
        case 2:
            std::cerr << "error: wrong input: range error" << std::endl;
            break;
    }

    return 0;
}