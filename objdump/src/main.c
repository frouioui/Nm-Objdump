/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump_2019
** File description:
** File of the main function of the program
*/

#include <stdlib.h>
#include <stdbool.h>
#include "objdump_program.h"
#include "helper.h"
#include "argument_parser.h"
#include "execution.h"
#include "execution_error.h"

int main(int argc, char **argv)
{
    objdump_program_t *obj = NULL;
    execution_error_t error = {0};

    obj = start_program(argv[0]);
    if (obj == NULL || obj->args == NULL)
        return (OBJ_FAILURE);
    get_argument(argc, argv, obj->args);
    if (obj->args->error.type != NO_ERROR_PARSER) {
        display_error(obj->prog_name, obj->args->error);
        return (OBJ_FAILURE);
    } else if (obj->args->display_helper == true) {
        display_helper();
        return (OBJ_SUCCESS);
    }
    error = execution(obj);
    if (error.type != NO_EXEC_ERROR)
        printf("%s: %s\n", obj->prog_name, error.message);
    return (error.type == NO_EXEC_ERROR ? OBJ_SUCCESS : OBJ_FAILURE);
}