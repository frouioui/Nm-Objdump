##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile for the NM program
##

BINARY_NAME = my_nm

CC	=	gcc $(HEADER)

WARNING	=	-W -Wextra -Werror

CFLAGS	=	$(WARNING)

HEADER	=	-I./include

OBJS	=	$(SRC:.c=.o)

PATH_SRC	=	./src

SRC			=	$(PATH_SRC)/main.c	\

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	gcc -o $(BINARY_NAME) $(OBJS) $(WARNING)

tests_run:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(BINARY_NAME) $(OBJS)

re: fclean all