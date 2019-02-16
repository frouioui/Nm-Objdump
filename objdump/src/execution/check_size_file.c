/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Check the size of the file
*/

#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "execution.h"
#include "execution_error.h"

static char *new_non_ordinary_file_error(char *path)
{
    char *str = calloc(1, sizeof(char) *
        (strlen(path) + 2 + strlen("Warning: '': is not an ordinary file")));

    str = strcat(str, "Warning: '");
    str = strcat(str, path);
    str = strcat(str, "': is not an ordinary file");
    return (str);
}

void check_size_file(execution_information_t *exec, char *path)
{
    exec->size = lseek(exec->fd, 0, SEEK_END);
    lseek(exec->fd, 0, SEEK_SET);
    if (exec->size < (int)sizeof(Elf64_Ehdr)) {
        close(exec->fd);
        exec->fd = -1;
        exec->error = new_execution_error(EXEC_FILE_IS_NOT_ORDINARY,
            new_non_ordinary_file_error(path), "check_size_file");
    }
}