/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the get_argument function
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "argument_parser.h"
#include "parser_error.h"

static bool check_file_flag_exists(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '\0' && argv[i][0] != '-') {
            return (true);
        }
    }
    return (false);
}

bool get_argument(int argc, char **argv, argument_parser_t *args)
{
    error_parser_t error = NO_ERROR_PARSER;

    if (check_file_flag_exists(argc, argv) == false) {
        get_filename("a.out", args);
    }
    for (int i = 1; i < argc && error == NO_ERROR_PARSER; i++) {
        if (strlen(argv[i]) > 2 && argv[i][0] == '-' && argv[i][1] == '-')
            error = check_each_long_flag(argv[i], args);
        else if (argv[i][0] == '-')
            error = check_each_short_flag(argv[i], args);
        else
            get_filename(argv[i], args);
    }
    return (error == NO_ERROR_PARSER ? true : false);
}