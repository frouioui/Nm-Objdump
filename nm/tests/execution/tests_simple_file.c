/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Simple_exec
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "nm_program.h"
#include "execution_error.h"
#include "execution.h"

Test(simple_exec, simple_exec_64)
{
    nm_program_t *nm = start_program("jul");
    argument_parser_t *args = init_argument();
    char **argv = malloc(sizeof(char *) * 3);

    argv[0] = strdup("./my_nm");
    argv[1] = strdup("./tests/assets/64_a.out");
    argv[2] = NULL;
    get_argument(2, argv, nm->args);
    execution(nm);
}

Test(simple_exec, simple_exec_32)
{
    nm_program_t *nm = start_program("jul");
    argument_parser_t *args = init_argument();
    char **argv = malloc(sizeof(char *) * 3);

    argv[0] = strdup("./my_nm");
    argv[1] = strdup("./tests/assets/32_a.out");
    argv[2] = NULL;
    get_argument(2, argv, nm->args);
    execution(nm);
}