/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Main header of the program. Contains the progam structure and constants
*/

#if !defined(_PROGRAM_H)
#define _PROGRAM_H

#include "argument_parser.h"

extern const unsigned int OBJ_SUCCESS;
extern const unsigned int OBJ_FAILURE;

struct program_s {
    char *prog_name;
    argument_parser_t *args;
};

typedef struct program_s objdump_program_t;

objdump_program_t *start_program(char *prog_path);

#endif // _PROGRAM_H
