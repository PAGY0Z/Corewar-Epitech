##
## EPITECH PROJECT, 2023
## B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
## File description:
## ASM Makefile (responsible of the compilation of the ASM-part of the project)
##

BIN_NAME	=	asm

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror

INCLUDES	=	-I./includes \
				-I./../lib/my/includes \
				-L./../lib/my -lmy

SRC_FILES	=	$(shell find . -name '*.c')

all:
	$(CC) -o $(BIN_NAME) $(SRC_FILES) $(INCLUDES) $(CFLAGS)

clean:
	rm -f $(BIN_NAME)

fclean: clean

re: fclean all
