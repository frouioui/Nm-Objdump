/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header file of the argument_parser functions and structure
*/

#if !defined(_ARGUMENT_PARSER_H )
#define _ARGUMENT_PARSER_H

#include <stdbool.h>

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
};

typedef struct argument_parser_s argument_parser_t;

argument_parser_t *init_argument(void);
bool get_argument(int argc, char **argv, argument_parser_t *args);

#endif // _ARGUMENT_PARSER_H

