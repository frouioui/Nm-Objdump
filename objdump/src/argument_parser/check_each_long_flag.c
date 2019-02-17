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

static int check_one_long_flag(char *arg, char const *flag)
{
    return (strcmp(arg, flag) == 0 ? 1 : -1);
}

static bool check_arg_is_empty(char *arg)
{
    return (strlen(arg) > 2 ? false : true);
}
static void apply_long_flag(unsigned int flag_nb, argument_parser_t *args)
{
    flag_nb == 0 ? args->display_helper = true : 0;
}

static char *create_new_parser_message_error(char *arg)
{
    char *error = calloc(1, sizeof(char) * (strlen(arg) +
                            strlen("unrecognized option '") + 2));

    if (error == NULL)
        return (NULL);
    error = strcat(error, "unrecognized option '");
    error = strcat(error, arg);
    error = strcat(error, "'");
    return (error);
}

error_parser_t check_each_long_flag(char *arg, argument_parser_t *args)
{
    error_parser_t error = INVALID_FLAG;
    unsigned int flag_nb = 0;

    if (check_arg_is_empty(arg) == true) {
        return INVALID_SYNTAX;
    }
    while (flag_nb < NUMBER_OF_LONG_FLAG) {
        if (check_one_long_flag(arg, long_flags[flag_nb]) >= 0) {
            apply_long_flag(flag_nb, args);
            error = NO_ERROR_PARSER;
            break;
        }
        flag_nb++;
    }
    args->error.message = create_new_parser_message_error(arg);
    return (error);
}