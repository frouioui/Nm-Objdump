/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump_2019
** File description:
** File of the main function of the program
*/

#include <stdlib.h>
#include <stdbool.h>
#include "argument_parser.h"

int main(int argc, char **argv)
{
    argument_parser_t *args = NULL;
    bool args_ok = false;

    args = init_argument();
    if (args == NULL)
        return (84);
    args_ok = get_argument(argc, argv, args);
    if (args_ok == false)
        return (84);
    return (args_ok);
}