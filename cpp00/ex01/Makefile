# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:37:03 by lorbke            #+#    #+#              #
#    Updated: 2023/05/02 15:58:14 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __________________________________________________________________ VARIABLES #

SHELL		:= /bin/bash

NAME		:= phonebook

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -std=c++98

SRC_PATH	:= src
SRC			:= PhoneBook.cpp Contact.cpp main.cpp
OBJ_PATH	:= obj
OBJ			:= $(SRC:%.cpp=$(OBJ_PATH)/%.o)
INC_PATH	:= inc

VPATH		:= $(SRC_PATH)

# _____________________________________________________________________ COLORS #

RED			:= \033[0;31m
GREEN		:= \033[0;32m
RESET		:= \033[0m

# ______________________________________________________________________ RULES #

.PHONY: all clean fclean re val

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) [OK]$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

make val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all
