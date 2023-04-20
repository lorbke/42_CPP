# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:37:03 by lorbke            #+#    #+#              #
#    Updated: 2023/04/17 21:56:07 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __________________________________________________________________ VARIABLES #

SHELL	:= /bin/bash

NAME	:= zombieHorde

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -std=c++98

SRCS	:= main.cpp Zombie.cpp zombieHorde.cpp
OBJS	:= $(SRCS:.cpp=.o)

# _____________________________________________________________________ COLORS #

RED		:= \033[0;31m
GREEN	:= \033[0;32m

# ______________________________________________________________________ RULES #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ______________________________________________________________ TESTING RULES #

test:
	@$(SHELL) tester/tester.sh

run: all
	@./$(NAME)

rawrun:
	@$(CC) $(SRCS) -o $(NAME)
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re test run rawrun val
