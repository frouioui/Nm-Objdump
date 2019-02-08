##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile for the NM program
##

## ---------------- NAMES ---------------- ##
BINARY_NAME		=	my_nm

BINARY_TEST_MAME =	unit_test

## ---------------- CC ---------------- ##
CC				=	gcc $(HEADER) -g3

## ---------------- FLAGS ---------------- ##
WARNING			=	-W -Wextra -Werror

CFLAGS			=	$(WARNING)

HEADER			=	-I./include

LDFLAGS = -lcriterion -lgcov --coverage

## ---------------- OBJS ---------------- ##
OBJS			=	$(SRC:.c=.o)											\
					$(MAIN_FILE_PATH:.c=.o)									\

## SRC ##
PATH_SRC		=	./src

MAIN_FILE_PATH	=	$(PATH_SRC)/main.c										\

SRC				=	$(PATH_SRC)/argument_parser/get_argument.c				\
					$(PATH_SRC)/argument_parser/init_argument.c				\
					$(PATH_SRC)/argument_parser/check_each_short_flag.c		\
					$(PATH_SRC)/argument_parser/check_each_long_flag.c		\
					$(PATH_SRC)/argument_parser/set_global_variable.c		\
					$(PATH_SRC)/argument_parser/get_filename.c				\
					$(PATH_SRC)/init_program/start_program.c				\
					$(PATH_SRC)/display_error.c								\

## ---------------- TESTS ---------------- ##
PATH_TEST		=	./tests

TEST_SRC		=	$(PATH_TEST)/argument_parser/tests_init_args.c				\
					$(PATH_TEST)/argument_parser/tests_check_each_short_flag.c	\
					$(PATH_TEST)/argument_parser/tests_check_each_long_flag.c	\
					$(PATH_TEST)/argument_parser/tests_get_filename.c			\
					$(PATH_TEST)/argument_parser/tests_get_argument.c			\

## ---------------- RULES ---------------- ##
all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	gcc -o $(BINARY_NAME) $(OBJS) $(WARNING)

tests_compile:
	gcc -o $(BINARY_TEST_MAME) $(TEST_SRC) $(SRC) $(CFLAGS) $(LDFLAGS) $(HEADER)

tests_run: tests_compile
	./$(BINARY_TEST_MAME) -j1

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc* $(OBJS)

fclean: clean
	rm -f $(BINARY_NAME) $(BINARY_TEST_MAME) $(OBJS)

re: fclean all