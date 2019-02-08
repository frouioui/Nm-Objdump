/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header of the elf function and struct
*/

#if !defined(_ELF_READER_H)
#define _ELF_READER_H

#include "argument_parser.h"
#include "execution.h"

void read_elf(argument_parser_t *args, execution_information_t *exec);

#endif // _ELF_READER_H
