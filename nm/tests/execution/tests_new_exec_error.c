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

Test(execution, check_new_error_empty)
{
    execution_error_t error;

    error = new_execution_error(NO_EXEC_ERROR, NULL, NULL);
    cr_assert_eq(error.type == NO_ERROR_PARSER, true);
    cr_assert_null(error.message);
    cr_assert_null(error.where);
}