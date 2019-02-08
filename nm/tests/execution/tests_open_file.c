/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Test file of the execution function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "execution_error.h"
#include "execution.h"

Test(execution, open_file_valid_file)
{
    execution_information_t *exec = init_execution_information();

    open_file(exec, "Makefile");
    cr_assert_gt(exec->fd, 2);
    cr_assert_eq(exec->error.type == NO_ERROR_PARSER, true);
}

Test(execution, open_file_invalid_file)
{
    execution_information_t *exec = init_execution_information();

    open_file(exec, "i am invalid");
    cr_assert_eq(exec->fd, -1);
    cr_assert_eq(exec->error.type == EXEC_NO_SUCH_FILE, true);
    cr_assert_str_eq(exec->error.message, "'i am invalid': No such file");
    cr_assert_str_eq(exec->error.where, "open_file");
}

Test(execution, open_file_no_file)
{
    execution_information_t *exec = init_execution_information();

    open_file(exec, NULL);
    cr_assert_eq(exec->fd, 0);
    cr_assert_eq(exec->error.type == NO_EXEC_ERROR, true);
}