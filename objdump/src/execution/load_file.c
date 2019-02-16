/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the main execution functions
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "objdump_program.h"
#include "execution.h"
#include "execution_error.h"

void load_file_in_memory(execution_information_t *exec)
{
    struct stat s = {0};

    fstat(exec->fd, &s);
    exec->file = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, exec->fd, 0);
    if (exec->file == NULL) {
        exec->error = new_execution_error(EXEC_INTERNAL_ERROR_MEMORY,
            "mmap error", "load_file_in_memory");
    }
}