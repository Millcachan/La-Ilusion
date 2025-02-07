##
## EPITECH PROJECT, 2024
## La-Ilusi-n
## File description:
## Makefile
##

.SILENT:

NAME    =   LaIlusion

CPROG   =   $(wildcard src/*.c src/*/*.c src/*/*/*.c)

OPROG	=	$(CPROG:.c=.o)

IFLAGS	=	-I./include/ -I./include/scene -I./include/usage

WFLAGS	=	-g -Wall -Wconversion -Wpedantic -O3 \
            -Wsign-compare -Wtype-limits -Walloc-zero \
            -Wmissing-field-initializers -Wunused-variable \
            -Wcast-qual -Wduplicated-branches \
            -Winit-self -Wuninitialized

CFLAGS  =   $(IFLAGS) $(WFLAGS) $(CSFMLFLAGS)

CSFMLFLAGS	= -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all: $(OPROG)
	gcc -o $(NAME) $(OPROG) $(CFLAGS)
	printf "[%s] — Successfully compiled\n" $(NAME)

clean:
	rm -f $(OPROG)
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g

debug: re
	printf "[%s] — Debug mode enabled\n" $(NAME)

.PHONY: all clean fclean re debug
