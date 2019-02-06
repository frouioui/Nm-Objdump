/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Get the filename out of the arguments
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "argument_parser.h"
#include "parser_error.h"

static void allocate_new_file_array(argument_parser_t *args)
{
    if (args->files == NULL)
        args->files = malloc(sizeof(char *) * (2));
}

void get_filename(char *arg, argument_parser_t *args)
{
    allocate_new_file_array(args);
    if (args->number_of_file > 0) {
        args->files = realloc(args->files, sizeof(char *) *
        (args->number_of_file + 2));
    }
    args->files[args->number_of_file] = strdup(arg);
    args->files[args->number_of_file + 1] = NULL;
    args->number_of_file++;
}