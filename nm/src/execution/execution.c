/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the main execution functions
*/

#include <stdlib.h>
#include "nm_program.h"
#include "execution.h"
#include "execution_error.h"

static bool is_errored(execution_information_t *exec)
{
    return (exec->error.type == NO_EXEC_ERROR ? false : true);
}

execution_error_t execution(nm_program_t *nm)
{
    execution_information_t *exec = init_execution_information();
    unsigned int file_index = 0;

    while (file_index < nm->args->number_of_file) {
        open_file(exec, nm->args->files[file_index]);
        if (is_errored(exec) == true)
            return (exec->error);
        load_file_in_memory(exec);
        if (is_errored(exec) == true)
            return (exec->error);
        close(exec->fd);
        file_index++;
    }
    // TODO: Destroy resources
    // destroy_execution_information(exec);
    return (new_execution_error(NO_ERROR_PARSER, NULL, NULL));
}