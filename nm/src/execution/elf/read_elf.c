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
    elf_info_t *elf_file = get_info_file(exec->file);

    if (elf_file == NULL)
        return;
    printf("is file valid = %d\n", is_magic_valid(exec->file));
    if (elf_file->arch == ARCH_64) {
        printf("FILE ARCH = 64\n");
    } else if (elf_file->arch == ARCH_32) {
        printf("FILE ARCH = 32\n");
    } else {
        printf("NO ARCH FOUND\n");
    }
}