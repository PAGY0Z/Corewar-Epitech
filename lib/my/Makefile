##
## EPITECH PROJECT, 2023
## PAGYOZ' Clib. Check it out at : https://github.com/PAGY0Z/my_lib_c
## File description:
## Library Makefile (responsible of the compilation of the project's library)
##

CC	=	gcc

AR	=	ar rc

CFLAGS	=	-W -Wall -Wextra -Werror -I./includes

NAME	=	libmy.a

LIB_SRC_FUNCS	=	$(shell find . -name '*.c')

OBJ	=	$(LIB_SRC_FUNCS:.c=.o)

all:	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(OBJ)

re:	fclean all
