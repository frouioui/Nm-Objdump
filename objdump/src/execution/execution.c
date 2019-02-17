/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the main execution functions
*/

#include <stdlib.h>
#include <sys/mman.h>
#include "objdump_program.h"
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
    if (exec->file) {
        munmap(exec->file, exec->size);
    }
    free(exec);
}

static execution_information_t *begin_execution_loop(objdump_program_t *obj,
    unsigned int i)
{
    execution_information_t *exec = NULL;

    exec = init_execution_information(obj->args->files[i]);
    obj->args->number_of_file > 1 ? printf("\n%s:\n", exec->name) : 0;
    open_file(exec, exec->name);
    return (exec);
}

execution_error_t execution(objdump_program_t *obj)
{
    execution_information_t *exec = NULL;
    execution_error_t error = new_execution_error(NO_EXEC_ERROR, NULL, NULL);

    for (unsigned int i = 0; i < obj->args->number_of_file; i++) {
        exec = begin_execution_loop(obj, i);
        error = exec->error;
        if (is_errored(exec) == true)
            continue;
        check_size_file(exec, exec->name);
        load_file_in_memory(exec);
        error = exec->error;
        if (is_errored(exec) == true)
            continue;
        read_elf(obj->args, exec);
        error = exec->error;
        if (is_errored(exec) == true)
            continue;
        release_exec_information(exec);
    }
    return (error);
}