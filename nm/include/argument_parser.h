/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header file of the argument_parser functions and structure
*/

#if !defined(_ARGUMENT_PARSER_H )
#define _ARGUMENT_PARSER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "parser_error.h"

struct argument_parser_s {
    bool display_filename;
    bool display_debug;
    bool numeric_sort;
    bool no_sort;
    bool reverse_sort;
    bool display_line_number;
    bool display_helper;
    bool display_size;
    bool display_undefined_only;
    bool display_defined_only;
    size_t number_of_file;
    char **files;
};

typedef struct argument_parser_s argument_parser_t;

// program's flag
extern const unsigned int NUMBER_OF_LONG_FLAG;
extern const unsigned int NUMBER_OF_SHORT_FLAG;
extern const char long_flags[10][20];
extern const char short_flags[9][2];


argument_parser_t *init_argument(void);
bool get_argument(int argc, char **argv, argument_parser_t *args);
error_parser_t check_each_short_flag(char *arg, argument_parser_t *args);
error_parser_t check_each_long_flag(char *arg, argument_parser_t *args);

#endif // _ARGUMENT_PARSER_H

