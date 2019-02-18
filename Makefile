##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile of the whole project
##

all:
	make -C ./nm && cp ./nm/my_nm .
	make -C ./objdump && cp ./objdump/my_objdump .

nm: nm_compile

nm_compile:
	make -C ./nm && cp ./nm/my_nm .

objdump: objdump_compile

objdump_compile:
	make -C ./objdump && cp ./objdump/my_objdump .

tests_run:
	make tests_compile -C ./nm && mv ./nm/unit_test ./unit_test_nm
	./unit_test_nm -j1 --always-succeed

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc*
	make clean -C ./nm
	make clean -C ./objdump

fclean: clean
	rm -f unit_test_nm my_nm my_objdump
	make fclean -C ./nm
	make fclean -C ./objdump

re: fclean all
