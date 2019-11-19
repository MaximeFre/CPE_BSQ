##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## c
##

SRC = 	bsq.c		\
		my_getnbr.c	\
		open_file.c	\

NAME = bsq

all: 	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -Iinclude -Wall -Wextra

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug:
	gcc -g -o $(NAME) $(SRC) -Iinclude -Wall -Wextra
