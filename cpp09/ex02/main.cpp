#include <iostream> // io, uint
#include <cstdlib> // strtol
#include <cctype> // isalnum
#include <cerrno>
#include <climits>
#include <vector>
#include "PmergeMe.hpp"
#include "StopWatch.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void debug_print_vector(std::vector<uint> vec);

bool is_str_only_num(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int parse(char** input, std::vector<uint>& numbers) {
    errno = 0;

    for (int i = 0; input[i]; i++) {
        if (!is_str_only_num(input[i]))
            return 1;
        numbers.push_back(strtol(input[i], NULL, 10));
        if (errno == ERANGE || numbers.back() > INT_MAX)
            return 2;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cerr << "usage: pmergeme { value }" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    StopWatch timer;

    switch (parse(++argv, sorter.numbers))
    {
        case 0:
            #ifdef DEBUG
                std::cout << "parsing success!" << std::endl;
            #endif
            break;
        case 1:
            std::cerr << "error: wrong input: invalid chars" << std::endl;
            return 1;
        case 2:
            std::cerr << "error: wrong input: range error" << std::endl;
            return 2;
    }

    std::cout << timer.getTime() << std::endl;
    timer.start();
    sorter.sort_numbers();
    timer.stop();
    std::cout << timer.getTime() << std::endl;

    #ifdef DEBUG
        std::cout << GREEN "sorted vector:" RESET << std::endl;
        debug_print_vector(sorter.numbers);
    #endif

    return 0;
}