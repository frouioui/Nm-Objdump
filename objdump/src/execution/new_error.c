/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Create a new error
*/

#include <stdlib.h>
#include <string.h>
#include "execution_error.h"

execution_error_t new_execution_error(execution_error_type_t type, char *msg,
    char *where)
{
    execution_error_t error;

    error.type = type;
    error.message = msg ? strdup(msg) : NULL;
    error.where = where ? strdup(where) : NULL;
    return (error);
}