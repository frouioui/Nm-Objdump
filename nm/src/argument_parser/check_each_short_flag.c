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

static int check_one_short_flag(char arg)
{
    bool found = false;
    int flag_nb = 0;

    while (flag_nb < NUMBER_OF_SHORT_FLAG && found == false) {
        for (unsigned int i = 0; short_flags[flag_nb][i] && !found; i++) {
            found = (arg == short_flags[flag_nb][i] ? true : false);
        }
        if (found == false)
            flag_nb++;
    }
    return (found == true ? flag_nb : -1);
}

static void apply_short_flag(unsigned int flag_nb, argument_parser_t *args)
{
    flag_nb == 0 ? args->display_filename = true : 0;
    flag_nb == 1 ? args->display_debug = true : 0;
    flag_nb == 2 ? args->display_line_number = true : 0;
    flag_nb == 3 ? args->numeric_sort = true : 0;
    flag_nb == 4 ? args->no_sort = true : 0;
    flag_nb == 5 ? args->reverse_sort = true : 0;
    flag_nb == 6 ? args->display_size = true : 0;
    flag_nb == 7 ? args->display_undefined_only = true : 0;
    flag_nb == 8 ? args->display_helper = true : 0;
}

error_parser_t check_each_short_flag(char *arg, argument_parser_t *args)
{
    error_parser_t error = INVALID_FLAG;
    int flag_nb;

    for (unsigned int i = 0; arg[i]; i++) {
        flag_nb = check_one_short_flag(arg[i]);
        if (flag_nb >= 0)
            apply_short_flag(flag_nb, args);
    }
    return (INVALID_FLAG);
}