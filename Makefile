##
## EPITECH PROJECT, 2024
## Project - la_ilusion
## File description:
## Makefile used to help
## and facilitate the compilation
## of la_ilusion
##

CC = gcc
CFLAGS =

NAME = la_ilusion

INCLUDE_DIR = include/

SRC_FILES = main.c								\

.PHONY = all debug clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRC_FILES) -I./$(INCLUDE_DIR)

debug: CFLAGS += -ggdb -Wall -Wextra -Werror
debug: fclean $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all
