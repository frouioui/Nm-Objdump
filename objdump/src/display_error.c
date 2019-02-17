/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the helper function
*/

#include <stdio.h>
#include "parser_error.h"
#include "helper.h"

void display_error(char *prog_name, error_parser_info_t error)
{
    printf("%s: %s\n", prog_name, error.message);
}