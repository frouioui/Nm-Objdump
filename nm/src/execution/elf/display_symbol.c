/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Display all the symbol of the given elf
*/

#include <elf.h>
#include <string.h>
#include <stdio.h>
#include "argument_parser.h"
#include "execution.h"
#include "elf_reader.h"

// FIXME: following line only useful if we need the real size
// printf("%0*x", ((elf->arch == ARCH_32) ? 8 : 16),
// (unsigned int)(elf->symbol_list[i].sym)->st_size);
static void display_one_symbol_line(argument_parser_t *args,
    execution_information_t *exec, elf_info_t *elf, unsigned int i)
{
    if (elf->symbol_list[i].name && strlen(elf->symbol_list[i].name) == 0)
        return;
    if (elf->symbol_list[i].sym->st_shndx == SHN_UNDEF)
        printf("%*c %s\n", ((elf->arch == ARCH_32) ? 8 : 16) + 2,
            elf->symbol_list[i].type, elf->symbol_list[i].name);
    else {
        printf("%0*x", ((elf->arch == ARCH_32) ? 8 : 16),
            elf->symbol_list[i].value);
        printf(" %c %s\n", elf->symbol_list[i].type, elf->symbol_list[i].name);
    }
}

void display_symbol(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf, unsigned int nb_symbol)
{
    order_symbol_list(args, elf, nb_symbol);
    for (unsigned int i = 0; i < nb_symbol; i++) {
        display_one_symbol_line(args, exec, elf, i);
    }
}