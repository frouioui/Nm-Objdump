/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the init_argument function
*/

#include <criterion/criterion.h>
#include "argument_parser.h"

Test(argument_parser, check_init_not_null)
{
    cr_assert_not_null(init_argument());
}

Test(argument_parser, check_init_default_value)
{
    argument_parser_t *args = NULL;

    args = init_argument();
    cr_assert_eq(args->display_filename, false);
    cr_assert_eq(args->display_debug, false);
    cr_assert_eq(args->numeric_sort, false);
    cr_assert_eq(args->no_sort, false);
    cr_assert_eq(args->reverse_sort, false);
    cr_assert_eq(args->display_line_number, false);
    cr_assert_eq(args->display_helper, false);
    cr_assert_eq(args->display_size, false);
    cr_assert_eq(args->display_undefined_only, false);
    cr_assert_eq(args->display_defined_only, false);
}