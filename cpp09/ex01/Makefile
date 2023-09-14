# __________________________________________________________________ VARIABLES #

SHELL    := /bin/bash

NAME     := RPN

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98

SRC_DIR  := src
SRC      := main.cpp RPN.cpp
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

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

run: all
	-@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo ------------------------------------------
	-@./$(NAME) "7 7 * 7 -"
	@echo ------------------------------------------
	-@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo ------------------------------------------
	-@./$(NAME) "(1 + 1)"
	@echo ------------------------------------------
	-@./$(NAME) "1 1 1"
	@echo ------------------------------------------
	-@./$(NAME) "1 1 1 +"
	@echo ------------------------------------------
	-@./$(NAME) "1 1 1 + -"
	@echo ------------------------------------------
	-@./$(NAME) "1 1 1 + - -"
	@echo ------------------------------------------
	-@./$(NAME) "1 0 /"
	@echo ------------------------------------------
	-@./$(NAME) ""
	@echo ------------------------------------------
	-@./$(NAME) "0"
	@echo ------------------------------------------
	-@./$(NAME) "42"
	@echo ------------------------------------------
	-@./$(NAME) "      "
	@echo ------------------------------------------
	

rawrun:
	@$(CXX) $(SRC) -o $(NAME)
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re test run rawrun val