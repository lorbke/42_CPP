# __________________________________________________________________ VARIABLES #

SHELL    := /bin/bash

NAME     := scalarconverter

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

SRC_DIR  := src
SRC      := main.cpp ScalarConverter.cpp
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

$(OBJ_DIR)/%.o: %.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

debug: CXXFLAGS += -DDEBUG
debug: re
	@echo -e "$(BLUE)DEBUG MODE ACTIVE$(RESET)"

run: all
	@echo ===========================================================
	-./$(NAME) 0
	@echo --------------------
	-./$(NAME) 0.0f
	@echo --------------------
	-./$(NAME) nan
	@echo --------------------
	-./$(NAME) 42.0f
	@echo --------------------
	-./$(NAME) 42.0xx
	@echo --------------------
	-./$(NAME) 42.42
	@echo --------------------
	-./$(NAME) -42.42
	@echo --------------------
	-./$(NAME) --42.42
	@echo --------------------
	-./$(NAME) +42.42
	@echo --------------------
	-./$(NAME) ++42.42
	@echo --------------------
	-./$(NAME) -42.42f
	@echo --------------------
	-./$(NAME) 2147483648
	@echo --------------------
	-./$(NAME) +inf
	@echo --------------------
	-./$(NAME) +inff
	@echo --------------------
	-./$(NAME) inf
	@echo --------------------
	-./$(NAME) inff
	@echo --------------------
	-./$(NAME) -inf
	@echo --------------------
	-./$(NAME) -inff
	@echo --------------------
	-./$(NAME) nan
	@echo --------------------
	-./$(NAME) nanf
	@echo --------------------
	-./$(NAME) 42+42
	@echo --------------------
	-./$(NAME) 42ff
	@echo --------------------
	-./$(NAME) 42..0
	@echo --------------------
	-./$(NAME) --42
	@echo --------------------
	-./$(NAME) 42.0ff
	@echo --------------------
	-./$(NAME) 0.+f
	@echo --------------------
	-./$(NAME) 42..0f

rawrun:
	@$(CXX) $(SRC) -o $(NAME)
	./$(NAME) 0
	@echo --------------------
	./$(NAME) 0.0f
	@echo --------------------
	./$(NAME) nan
	@echo --------------------
	./$(NAME) 42.0f
	@echo --------------------
	./$(NAME) 42.42
	@echo --------------------
	./$(NAME) -42.42f
	@echo --------------------
	./$(NAME) 2147483648

val: all
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re test run rawrun val