/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the get_filename function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "argument_parser.h"

Test(argument_parser, get_filename_first_file)
{
    argument_parser_t *args = init_argument();
    char *arg = strdup("my_file.txt");

    cr_assert_null(args->files);
    cr_assert_eq(args->number_of_file, 0);
    get_filename(arg, args);
    cr_assert_not_null(args->files);
    cr_assert_not_null(args->files[0]);
    cr_assert_str_eq(args->files[0], "my_file.txt");
    cr_assert_null(args->files[1]);
    cr_assert_eq(args->number_of_file, 1);
}

Test(argument_parser, get_filename_realloc_file)
{
    argument_parser_t *args = init_argument();
    char *arg_first = strdup("my_file.txt");
    char *arg_second = strdup("my_second_file.txt");

    cr_assert_null(args->files);
    cr_assert_eq(args->number_of_file, 0);
    get_filename(arg_first, args);
    get_filename(arg_second, args);
    cr_assert_not_null(args->files);
    cr_assert_not_null(args->files[0]);
    cr_assert_not_null(args->files[1]);
    cr_assert_str_eq(args->files[0], "my_file.txt");
    cr_assert_str_eq(args->files[1], "my_second_file.txt");
    cr_assert_null(args->files[2]);
    cr_assert_eq(args->number_of_file, 2);
}