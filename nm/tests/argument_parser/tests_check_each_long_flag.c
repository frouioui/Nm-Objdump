/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the check_each_long_falg function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "argument_parser.h"
#include "parser_error.h"

Test(argument_parser, check_each_long_flag_correct_simple_string_1)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("--defined-only");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_long_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == NO_ERROR_PARSER, true);
    cr_assert_eq(args->display_defined_only, true);
}

Test(argument_parser, check_each_long_flag_correct_simple_string_2)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("--line-numbers");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_long_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == NO_ERROR_PARSER, true);
    cr_assert_eq(args->display_line_number, true);
}

Test(argument_parser, check_each_long_flag_correct_simple_string_3)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("--help");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_long_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == NO_ERROR_PARSER, true);
    cr_assert_eq(args->display_helper, true);
}

Test(argument_parser, check_each_long_flag_not_correct_simple_string)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("--imma_flag");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_long_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == INVALID_FLAG, true);
}

Test(argument_parser, check_each_long_flag_empty, .timeout = 0.01)
{
    error_parser_t return_value = NO_ERROR_PARSER;
    char *argv = strdup("--");
    argument_parser_t *args = init_argument();

    cr_assert_not_null(argv);
    return_value = check_each_long_flag(argv, args);
    cr_assert_not_null(argv);
    cr_assert_eq(return_value == INVALID_SYNTAX, true);
}