/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header file of the helper functions
*/

#if !defined(_HELPER_H)
#define _HELPER_H

#include "parser_error.h"

extern const char HELPER[200];

void display_helper(void);
void display_error(char *prog_name, error_parser_info_t error);

#endif // _HELPER_H
