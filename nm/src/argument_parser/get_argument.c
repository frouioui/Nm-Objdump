/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the get_argument function
*/

#include <stdbool.h>
#include <unistd.h>
#include "argument_parser.h"
#include "parser_error.h"

const char long_flags[NUMBER_OF_LONG_FLAG][20] = {
    {"--print-file-name"},
    {"--debug-syms"},
    {"--line-numbers"},
    {"--numeric-sort"},
    {"--no-sort"},
    {"--reverse-sort"},
    {"--print-size"},
    {"--undefined-only"},
    {"--defined-only"},
    {"--help"}
};

const char short_flags[NUMBER_OF_SHORT_FLAG][2] = {
    {{'A'}, {'o'}},
    {{'a'}, {'\0'}},
    {{'l'}, {'\0'}},
    {{'n'}, {'v'}},
    {{'p'}, {'\0'}},
    {{'r'}, {'\0'}},
    {{'S'}, {'\0'}},
    {{'u'}, {'\0'}},
    {{'h'}, {'\0'}}
};

bool get_argument(int argc, char **argv, argument_parser_t *args)
{
    if (argc < 2)
        return (true);
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) > 2 && argv[i][0] == '-' && argv[i][1] == '-')
            check_each_long_flag(argv[i], args);
        else if (argv[i][0] == '-')
            check_each_short_flag(argv[i], args);
    }
    return (false);
}