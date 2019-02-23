/*
** EPITECH PROJECT, 2019
** NM_Objdump
** File description:
** Source file
*/

#include <elf.h>
#include <string.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

int has_syms(Elf64_Ehdr *elf)
{
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++) {
        if (head[i].sh_type == SHT_SYMTAB)
            return (HAS_SYMS);
    }
    return (0);
}

int has_syms_32(Elf32_Ehdr *elf)
{
    Elf32_Shdr *head = (Elf32_Shdr *) ((char *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++) {
        if (head[i].sh_type == SHT_SYMTAB)
            return (HAS_SYMS);
    }
    return (0);
}