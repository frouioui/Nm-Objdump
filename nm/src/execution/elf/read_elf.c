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
    elf_info_t *elf_file = get_info_file(exec->file, exec->fd);

    if (elf_file == NULL)
        return;
    if (elf_file->static_lib == true) {
        printf("it is a static lib\n");
    } else {
        printf("it is not a static lib\n");
        if (is_magic_valid(elf_file->header) == true) {
            printf("and it is a valid elf file\n");
        } else {
            printf("but it is not a valid elf file\n");
        }
    }
}