/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the main execution functions
*/

#include <stdlib.h>
#include <sys/mman.h>
#include "nm_program.h"
#include "execution.h"
#include "execution_error.h"
#include "elf_reader.h"

static bool is_errored(execution_information_t *exec)
{
    return (exec->error.type == NO_EXEC_ERROR ? false : true);
}

static void release_exec_information(execution_information_t *exec)
{
    if (exec->fd > 2) {
        close(exec->fd);
    }
    // TODO: unmap the file pointer, we need to know the size of the pointer
    free(exec);
}

execution_error_t execution(nm_program_t *nm)
{
    execution_information_t *exec = NULL;
    unsigned int file_index = 0;

    while (file_index < nm->args->number_of_file) {
        exec = init_execution_information(nm->args->files[file_index]);
        open_file(exec, exec->name);
        if (is_errored(exec) == true)
            return (exec->error);
        check_size_file(exec, exec->name);
        load_file_in_memory(exec);
        if (is_errored(exec) == true)
            return (exec->error);
        read_elf(nm->args, exec);
        if (is_errored(exec) == true)
            return (exec->error);
        release_exec_information(exec);
        file_index++;
    }
    return (new_execution_error(NO_ERROR_PARSER, NULL, NULL));
}