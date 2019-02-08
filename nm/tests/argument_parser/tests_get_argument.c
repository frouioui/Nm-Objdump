/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the get_argument function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "argument_parser.h"

Test(argument_parser, get_argument_no_argument)
{
    argument_parser_t *args = init_argument();
    char **argv = malloc(sizeof(char *) * 2);

    argv[0] = strdup("./my_nm");
    argv[1] = NULL;
    get_argument(1, argv, args);
    cr_assert_eq(args->error.type == NO_ERROR_PARSER, true);
    cr_assert_not_null(args);
    cr_assert_not_null(args->files);
    cr_assert_str_eq(args->files[0], "a.out");
    cr_assert_null(args->files[1]);
    cr_assert_eq(args->number_of_file, 1);
}

Test(argument_parser, get_argument_various_argument)
{
    argument_parser_t *args = init_argument();
    char **argv = malloc(sizeof(char *) * 5);

    argv[0] = strdup("./my_nm");
    argv[1] = strdup("-o");
    argv[2] = strdup("--defined-only");
    argv[3] = strdup("file.txt");
    argv[4] = NULL;
    get_argument(4, argv, args);
    cr_assert_eq(args->error.type == NO_ERROR_PARSER, true);
    cr_assert_str_eq(args->files[0], "file.txt");
    cr_assert_eq(args->display_defined_only, true);
    cr_assert_eq(args->display_filename, true);
}

Test(argument_parser, get_argument_various_argument_no_given_file)
{
    argument_parser_t *args = init_argument();
    char **argv = malloc(sizeof(char *) * 5);

    argv[0] = strdup("./my_nm");
    argv[1] = strdup("-o");
    argv[2] = strdup("--defined-only");
    argv[3] = strdup("-h");
    argv[4] = NULL;
    get_argument(4, argv, args);
    cr_assert_eq(args->error.type == NO_ERROR_PARSER, true);
    cr_assert_str_eq(args->files[0], "a.out");
    cr_assert_eq(args->display_defined_only, true);
    cr_assert_eq(args->display_filename, true);
    cr_assert_eq(args->display_helper, true);
}