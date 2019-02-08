/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header of the execution function and struct
*/

#if !defined(_EXECUTION_H)
#define _EXECUTION_H

#include "nm_program.h"
#include "execution_error.h"

struct execution_information_s {
    int fd;
    void *file;
    execution_error_t error;
};

typedef struct execution_information_s execution_information_t;

execution_information_t *init_execution_information();
void open_file(execution_information_t *exec, char *path);
execution_error_t execution(nm_program_t *nm);

#endif // _EXECUTION_H
