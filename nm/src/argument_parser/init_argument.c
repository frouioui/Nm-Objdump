/*
** EPITECH PROJECT, 2019
** PSU_Nmobjdump
** File description:
** Initialisation of the argument structure
*/

#include <stdlib.h>
#include "argument_parser.h"

static void set_values_to_false(argument_parser_t *args)
{
    args->display_filename = false;
    args->display_debug = false;
    args->numeric_sort = false;
    args->no_sort = false;
    args->reverse_sort = false;
    args->display_line_number = false;
    args->display_helper = false;
    args->display_size = false;
    args->display_undefined_only = false;
    args->display_defined_only = false;
}

argument_parser_t *init_argument(void)
{
    argument_parser_t *args = malloc(sizeof(argument_parser_t));

    if (args == NULL)
        return (NULL);
    set_values_to_false(args);
    return (args);
}