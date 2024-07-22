##
## EPITECH PROJECT, 2024
## B-AIA-200-TLS-2-1-n4s-dytoma.batogouma
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

CFLAGS	=	-Iinclude/ -lc -lm

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf *~
	rm -rf *#

fclean: clean
	rm -rf $(NAME)

re: fclean all
