/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Init the main struct of the program
*/

#include <stdlib.h>
#include <libgen.h>
#include "objdump_program.h"

const unsigned int OBJ_SUCCESS = 0;
const unsigned int OBJ_FAILURE = 84;

objdump_program_t *start_program(char *prog_path)
{
    objdump_program_t *program = malloc(sizeof(objdump_program_t));

    if (program == NULL)
        return (NULL);
    program->prog_name = basename(prog_path);
    program->args = init_argument();
    return (program);
}