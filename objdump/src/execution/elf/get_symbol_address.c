/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Execute one signle file
*/

#include <elf.h>
#include <string.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static bool check_out_of_bond_64(elf_info_t *elf, Elf64_Ehdr *header,
    Elf64_Shdr *shdr)
{
    if ((void *)(shdr + 1) > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)STR_SEC > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    if ((void *)&(shdr[header->e_shnum])
        > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    return (true);
}

static bool check_out_of_bond_32(elf_info_t *elf, Elf32_Ehdr *header,
        Elf32_Shdr *shdr)
{
    if ((void *)(shdr + 1) > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)STR_SEC > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    if ((void *)&(shdr[header->e_shnum])
        > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    return (true);
}

static bool get_address_symbol_32(elf_info_t *elf,
    execution_information_t *exec)
{
    Elf32_Shdr *shdr = (Elf32_Shdr *)elf->shdr;
    Elf32_Ehdr *header = (Elf32_Ehdr *)elf->header;

    if (check_out_of_bond_32(elf, header, shdr) == false)
        return (false);
    return (true);
}

static bool get_address_symbol_64(elf_info_t *elf,
    execution_information_t *exec)
{
    Elf64_Shdr *shdr = elf->shdr;
    Elf64_Ehdr *header = elf->header;

    if (check_out_of_bond_64(elf, header, shdr) == false)
        return (false);
    return (true);
}

void get_address_symbol(elf_info_t *elf, execution_information_t *exec)
{
    bool valid = false;

    if (elf->arch == ARCH_32) {
        valid = get_address_symbol_32(elf, exec);
    } else if (elf->arch == ARCH_64) {
        valid = get_address_symbol_64(elf, exec);
    }
    if (valid == false) {
        exec->error = new_execution_error(EXEC_TRUNCATED,
            strcat(elf->path, ": File format not recognized"), NULL);
    }
}