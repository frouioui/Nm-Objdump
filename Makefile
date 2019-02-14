##
## EPITECH PROJECT, 2019
## PSU_NmObjdump
## File description:
## Makefile of the whole project
##

all:
	make -C ./nm && cp ./nm/my_nm .

nm:
	make -C ./nm && cp ./nm/my_nm .

objdump:
	echo "PAS TROP VITE SVPPPPPPPPP"

tests_run:
#	make tests_compile -C ./nm && mv ./nm/unit_test ./unit_test_nm
#	./unit_test_nm -j1 --always-succeed

tests_run_docker:
	docker run -v $(PWD):/app epitechcontent/epitest-docker bash -c "cd app && make fclean && make tests_run && gcovr"

clean:
	rm -f *.gc*
	make clean -C ./nm

fclean: clean
	rm -f unit_test_nm my_nm
	make fclean -C ./nm

re: fclean all
