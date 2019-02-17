/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Init the execution_information struct
*/

#include <stdlib.h>
#include "execution.h"
#include "execution_error.h"

execution_information_t *init_execution_information(char *path)
{
    execution_information_t *exec = NULL;

    exec = malloc(sizeof(execution_information_t));
    if (exec == NULL)
        return (NULL);
    exec->error = new_execution_error(NO_ERROR_PARSER, NULL, NULL);
    exec->fd = 0;
    exec->file = NULL;
    exec->name = path;
    return (exec);
}