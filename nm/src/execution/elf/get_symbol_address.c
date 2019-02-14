/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Execute one signle file
*/

#include <elf.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static bool check_out_of_bond_64(elf_info_t *elf, Elf64_Ehdr *header,
    Elf64_Shdr *symtab, Elf64_Shdr *shdr)
{
    if ((void *)STR_SYMB > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)STR_SEC > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)((void *)header + symtab->sh_offset) + symtab->sh_size
        > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    return (true);
}

static bool check_out_of_bond_32(elf_info_t *elf, Elf32_Ehdr *header,
    Elf32_Shdr *symtab, Elf32_Shdr *shdr)
{
    if ((void *)STR_SYMB > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)STR_SEC > (void *)((void *)elf->header + elf->size)) {
        return (false);
    } else if ((void *)((void *)header + symtab->sh_offset) + symtab->sh_size
        > (void *)((void *)elf->header + elf->size)) {
        return (false);
    }
    return (true);
}

static void get_address_symbol_32(elf_info_t *elf,
    execution_information_t *exec)
{
    Elf32_Shdr *shdr = (Elf32_Shdr *)elf->shdr;
    Elf32_Shdr *symtab = NULL;
    Elf32_Ehdr *header = (Elf32_Ehdr *)elf->header;

    // TODO: Check not out range
    for (unsigned int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            elf->symtab = ((Elf64_Shdr *)&(shdr[i]));
            symtab = (Elf32_Shdr *)elf->symtab;
        }
    }
    if (!elf->symtab) {
        exec->error = new_execution_error(EXEC_NO_SYMBOL,
            "given file has no symbol", NULL);
        return;
    }
    if (check_out_of_bond_32(elf, header, symtab, shdr) == false)
        exec->error = new_execution_error(EXEC_TRUNCATED,
            "given file is truncated", NULL);
}

static void get_address_symbol_64(elf_info_t *elf,
    execution_information_t *exec)
{
    Elf64_Shdr *shdr = elf->shdr;
    Elf64_Shdr *symtab = NULL;
    Elf64_Ehdr *header = elf->header;

    // TODO: Check not out range
    for (unsigned int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            symtab = ((Elf64_Shdr *)&(shdr[i]));
            elf->symtab = symtab;
        }
    }
    if (!elf->symtab) {
        exec->error = new_execution_error(EXEC_NO_SYMBOL,
            "given file has no symbol", NULL);
        return;
    }
    if (check_out_of_bond_64(elf, header, symtab, shdr) == false)
        exec->error = new_execution_error(EXEC_TRUNCATED,
            "given file is truncated", NULL);
}

void get_address_symbol(elf_info_t *elf, execution_information_t *exec)
{
    if (elf->arch == ARCH_32) {
        get_address_symbol_32(elf, exec);
    } else if (elf->arch == ARCH_64) {
        get_address_symbol_64(elf, exec);
    }
}