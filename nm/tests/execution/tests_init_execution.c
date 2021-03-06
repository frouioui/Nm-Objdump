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

Test(execution, check_value_not_null)
{
    execution_information_t *exec = NULL;

    exec = init_execution_information("jul");
    cr_assert_not_null(exec);
    cr_assert_str_eq(exec->name, "jul");
}

Test(execution, check_value_value)
{
    execution_information_t *exec = NULL;

    exec = init_execution_information("julll");
    cr_assert_eq(exec->fd, 0);
    cr_assert_str_eq(exec->name, "julll");
}