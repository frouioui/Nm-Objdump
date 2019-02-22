/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump_2019
** File description:
** File containing functions
*/

#include <stdlib.h>
#include <stdbool.h>
#include "nm_program.h"
#include "helper.h"
#include "argument_parser.h"
#include "execution.h"
#include "execution_error.h"

int main(int argc, char **argv)
{
    nm_program_t *nm = NULL;
    execution_error_t error;

    nm = start_program(argv[0]);
    if (nm == NULL || nm->args == NULL)
        return (NM_FAILURE);
    get_argument(argc, argv, nm->args);
    if (nm->args->error.type != NO_ERROR_PARSER) {
        display_error(nm->prog_name, nm->args->error);
        return (NM_FAILURE);
    } else if (nm->args->display_helper == true) {
        display_helper();
        return (NM_SUCCESS);
    }
    error = execution(nm);
    if (error.type != NO_EXEC_ERROR)
        printf("nm: %s\n", error.message);
    return (error.type == NO_EXEC_ERROR ? NM_SUCCESS : NM_FAILURE);
}