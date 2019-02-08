/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Main elf reader file
*/

#include <elf.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

void read_elf(argument_parser_t *args, execution_information_t *exec)
{
    Elf64_Ehdr *elf = exec->file;

    printf("%d\n", elf->e_ident[EI_CLASS]);
}