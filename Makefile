##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile of the whole project
##

BINARY_UT_NAME = unit_tests

CC	=	gcc

PATH_TEST = ./tests

UT_SRC =	\

CFLAGS	=	-W -Wextra -Werror

LDFLAGS = -lcriterion -lgcov --coverage

all:
	make -C ./nm && cp ./nm/my_nm .

tests_run:
	g++ -o $(BINARY_UT_NAME) $(UT_SRC) $(SRC) $(CFLAGS) $(LDFLAGS) $(HEADER)
	./$(BINARY_UT_NAME) -j1

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(BINARY_UT_NAME) my_nm
	make fclean -C ./nm

re: fclean all