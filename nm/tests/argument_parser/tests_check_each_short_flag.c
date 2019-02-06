/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the check_each_short_falg function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "argument_parser.h"
#include "parser_error.h"

Test(argument_parser, check_each_short_flag_correct_simple_string)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("-r");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_short_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == NO_ERROR_PARSER, true);
    cr_assert_eq(args->reverse_sort, true);
}

Test(argument_parser, check_each_short_flag_not_correct_simple_string)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("-K");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_short_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == INVALID_FLAG, true);
}

Test(argument_parser, check_each_short_flag_correct_complex_string)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("-rlh");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_short_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == NO_ERROR_PARSER, true);
    cr_assert_eq(args->reverse_sort, true);
    cr_assert_eq(args->display_line_number, true);
    cr_assert_eq(args->display_helper, true);
}

Test(argument_parser, check_each_short_flag_not_correct_complex_string)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("-rlQh");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_short_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == INVALID_FLAG, true);
}

Test(argument_parser, check_each_short_flag_empty, .timeout = 0.01)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("-");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_short_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == INVALID_SYNTAX, true);
}