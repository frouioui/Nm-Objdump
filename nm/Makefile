##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile for the NM program
##

BINARY_NAME = my_nm

CC	=	gcc $(HEADER) -g3

WARNING	=	-W -Wextra -Werror

CFLAGS	=	$(WARNING)

HEADER	=	-I./include

OBJS	=	$(SRC:.c=.o)

PATH_SRC	=	./src

SRC			=	$(PATH_SRC)/main.c	\
				$(PATH_SRC)/argument_parser/get_argument.c \
				$(PATH_SRC)/argument_parser/init_argument.c \

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS)
	gcc -o $(BINARY_NAME) $(OBJS) $(WARNING)

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(BINARY_NAME) $(OBJS)

re: fclean all