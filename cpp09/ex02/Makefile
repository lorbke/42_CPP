# __________________________________________________________________ VARIABLES #

SHELL    := /bin/bash

NAME     := pmergeme

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

SRC_DIR  := src
SRC      := main.cpp Debug.cpp PmergeMe.cpp StopWatch.cpp MergeSort.cpp \
			OptInsertionSort.cpp
OBJ_DIR  := obj
OBJ      := $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

INC_DIR  := inc

VPATH    := $(SRC_DIR)

# ______________________________________________________________ COLORS #

RED      := \033[0;31m
GREEN    := \033[0;32m
BLUE     := \033[0;34m
RESET    := \033[0m

# ______________________________________________________________________ RULES #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) [OK]$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp Debug.hpp PmergeMe.hpp StopWatch.hpp MergeSort.hpp \
				OptInsertionSort.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

run: all
	@./$(NAME)

debug: CXXFLAGS += -DDEBUG
debug: re
	@echo -e "$(BLUE)DEBUG MODE ACTIVE$(RESET)"

test: all
	-./$(NAME)
	@echo -e "-------------------------------------"
	-./$(NAME) 1
	@echo -e "-------------------------------------"
	-./$(NAME) 1 2
	@echo -e "-------------------------------------"
	-./$(NAME) "1 3 2"
	@echo -e "-------------------------------------"
	-./$(NAME) 1 1
	@echo -e "-------------------------------------"
	-./$(NAME) a d 1
	@echo -e "-------------------------------------"
	-./$(NAME) -1 1 0
	@echo -e "-------------------------------------"
	-./$(NAME) 1 1
	@echo -e "-------------------------------------"
	-./$(NAME) 2147483647
	@echo -e "-------------------------------------"
	-./$(NAME) 2147483648
	@echo -e "-------------------------------------"
	-./$(NAME) $$(./generate_numbers.sh)
	# @echo -e "-------------------------------------"
	# -./$(NAME) 50 1 49 2 48 3 47 4 46 5 45 6 44 7 43 8 42 9 0 41 10 40 11 39 12 38 13 37 14 36 15 35 1 16 34 17 33 18 32 19 31 20 30 21 29 22 28 23 27 1 1 24 26 25


rawrun:
	@$(CXX) $(SRC) -o $(NAME)
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re test run rawrun val