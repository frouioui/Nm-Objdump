/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Check if flag in order to find a match with the given key
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "argument_parser.h"
#include "parser_error.h"

static int check_one_long_flag(char *arg, char *flag)
{
    return (strcmp(arg, flag) == 0 ? 1 : -1);
}

static void apply_long_flag(unsigned int flag_nb, argument_parser_t *args)
{
    flag_nb == 0 ? args->display_filename = true : 0;
    flag_nb == 1 ? args->display_debug = true : 0;
    flag_nb == 2 ? args->display_line_number = true : 0;
    flag_nb == 3 ? args->numeric_sort = true : 0;
    flag_nb == 4 ? args->no_sort = true : 0;
    flag_nb == 5 ? args->reverse_sort = true : 0;
    flag_nb == 6 ? args->display_size = true : 0;
    flag_nb == 7 ? args->display_undefined_only = true : 0;
    flag_nb == 8 ? args->display_defined_only = true : 0;
    flag_nb == 9 ? args->display_helper = true : 0;
}

error_parser_t check_each_long_flag(char *arg, argument_parser_t *args)
{
    error_parser_t error = INVALID_FLAG;
    unsigned int flag_nb;

    while (flag_nb < NUMBER_OF_LONG_FLAG) {
        if (check_one_long_flag(arg, long_flags[flag_nb]) >= 0) {
            apply_long_flag(flag_nb, args);
            error = NO_ERROR_PARSER;
            break;
        }
        flag_nb++;
    }
    return (INVALID_FLAG);
}