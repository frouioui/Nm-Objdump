/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Main elf reader file
*/

#include <elf.h>
#include "elf_reader.h"
#include "execution.h"
#include "execution_error.h"
#include "parser_error.h"

static void get_section_header_address(elf_info_t *elf)
{
    if (elf->arch == ARCH_32) {
        elf->shdr = (Elf64_Shdr *)((char *)elf->header +
            ((Elf32_Ehdr *)elf->header)->e_shoff);
    } else if (elf->arch == ARCH_64) {
        elf->shdr = (Elf64_Shdr *)((char *)elf->header + elf->header->e_shoff);
    }
}

void read_elf(argument_parser_t *args, execution_information_t *exec)
{
    elf_info_t *elf_file = get_info_file(exec->file, exec->fd, exec->name,
        exec->size);

    if (elf_file == NULL)
        return;
    if (elf_file->arch == ARCH_NOT_FOUND) {
        exec->error = new_execution_error(EXEC_NO_ARCH, "no arch found", NULL);
        return;
    }
    if (elf_file->static_lib == true) {
        // TODO: Handle AR file
    } else {
        get_section_header_address(elf_file);
        get_address_symbol(elf_file, exec);
        if (elf_file->arch == ARCH_32 && !exec->error.type) {
            exec_elf_32(args, exec, elf_file);
        } else if (elf_file->arch == ARCH_64 && !exec->error.type) {
            exec_elf_64(args, exec, elf_file);
        }
    }
}