# __________________________________________________________________ VARIABLES #

SHELL    := /bin/bash

NAME     := pmergeme

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

SRC_DIR  := src
SRC      := main.cpp PmergeMe.cpp
OBJ_DIR  := obj
OBJ      := $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

INC_DIR  := inc

VPATH    := $(SRC_DIR)

# ______________________________________________________________ COLORS #

RED      := \033[0;31m
GREEN    := \033[0;32m
RESET    := \033[0m

# ______________________________________________________________________ RULES #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) [OK]$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

run: all
	@./$(NAME)

debug: CXXFLAGS += -DDEBUG=1
debug: re

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


rawrun:
	@$(CXX) $(SRC) -o $(NAME)
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re test run rawrun val