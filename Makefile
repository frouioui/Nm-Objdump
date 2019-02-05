##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile of the whole project
##

all:
	make -C ./nm && cp ./nm/my_nm .

tests_run:
	make tests_compile -C ./nm && mv ./nm/unit_test ./unit_test_nm
	./unit_test_nm -j1

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc*

fclean: clean
	rm -f unit_test_nm my_nm
	make fclean -C ./nm

re: fclean all