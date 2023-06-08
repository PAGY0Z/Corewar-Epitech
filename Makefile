##
## EPITECH PROJECT, 2023
## B-CPE-200-RUN-2-1-corewar-pierre-alexandre.grosset
## File description:
## Global Makefile (responsible of the compilation of the whole project)
##

ASM	=	asm/

COR	=	corewar/

LIB	=	lib/my

TESTS	=	tests/

CFLAGS	=	-W -Wall -Wextra -Werror

TFLAGS	=	--coverage -lcriterion

INCLUDE_TESTS	=	-I./lib/my/includes \
					-I./tests/includes \
					-I./asm/includes \
					-I./corewar/includes

TESTS_LIB_SRC_FILES	=	$(shell find $(LIB) -name '*.c')

TESTS_ASM_SRC_FILES	=	$(shell find $(ASM) -name '*.c' -not -name 'main.c')

TESTS_COR_SRC_FILES	=	$(shell find $(COR) -name '*.c' -not -name 'main.c')

TESTS_SRC_FILES	=	$(shell find $(TESTS) -name '*.c')

TESTS_SRC_GLOBALS	=	$(TESTS_LIB_SRC_FILES) \
						$(TESTS_ASM_SRC_FILES) \
						$(TESTS_COR_SRC_FILES) \
						$(TESTS_SRC_FILES)

all:
	make -C $(LIB)
	make -C $(ASM)
	make -C $(COR)

tests_run:
	$(CC) -o unit_test $(TESTS_SRC_GLOBALS) $(INCLUDE_TESTS) $(TFLAGS) $(CFLAGS)
	./unit_test && gcovr -e tests/ && gcovr -e tests/ -b

tests_clean:
	rm -f unit_test *.gcda *.gcno

tests_re : tests_clean tests_run

clean:
	make -C $(ASM) clean
	make -C $(COR) clean

fclean: clean tests_clean
	make -C $(LIB) fclean
	make -C $(ASM) fclean
	make -C $(COR) fclean
	@rm -rf *.cor

re: fclean all
