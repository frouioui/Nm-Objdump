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

static void get_address(elf_info_t *elf)
{
    if (elf->arch == ARCH_32) {
        elf->shdr = (Elf64_Shdr *)((char *)elf->header +
            ((Elf32_Ehdr *)elf->header)->e_shoff);
    }
    elf->shdr = (Elf64_Shdr *)((char *)elf->header + elf->header->e_shoff);
}

void read_elf(argument_parser_t *args, execution_information_t *exec)
{
    elf_info_t *elf_file = get_info_file(exec->file, exec->fd, exec->name);

    if (elf_file == NULL)
        return;
    if (elf_file->static_lib == true) {
        // TODO: Handle AR file
    } else {
        get_address(elf_file);
        get_address_symbol(elf_file, exec);
        if (elf_file->arch == ARCH_32) {

        } else if (elf_file->arch == ARCH_64) {
            exec_elf_64(args, exec, elf_file);
        }
    }
}