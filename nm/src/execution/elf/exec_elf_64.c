/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Exec the given file for 64bits
*/

#include <elf.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static symbol_list_t *new_symbol_list(unsigned int size)
{
    symbol_list_t *new = NULL;

    new = calloc(1, sizeof(symbol_list_t) * size);
    return (new);
}

static void find_one_symbol(argument_parser_t *args, Elf64_Sym *sym,
    elf_info_t *elf, int *i)
{
    Elf64_Ehdr *header = elf->header;
    Elf64_Shdr *shdr = elf->shdr;
    Elf64_Shdr *symtab = elf->symtab;

    // TODO: Accept the debug symbol
    if (sym->st_name > 0 && sym->st_info != STT_FILE) {
        elf->symbol_list[*i].sym = sym;
        if (sym->st_info == STT_SECTION && sym->st_shndx <= header->e_shnum &&
            sym->st_name == 0) {
            elf->symbol_list[*i].name = &((char *)header +
            shdr[header->e_shstrndx].sh_offset)[shdr[sym->st_shndx].sh_name];
        } else {
            elf->symbol_list[*i].name = &((char *)header +
                shdr[symtab->sh_link].sh_offset)[sym->st_name];
        }
        elf->symbol_list[*i].value = sym->st_value;
        elf->symbol_list[*i].type = guess_type_64(header, shdr, sym);
        (*i)++;
    }
}

void exec_elf_64(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf)
{
    unsigned int total_nb_symb = 0;
    Elf64_Ehdr *header = elf->header;
    Elf64_Shdr *symtab = elf->symtab;
    Elf64_Sym *sym = (Elf64_Sym *)((char *)header + symtab->sh_offset);

    elf->symbol_list = new_symbol_list(symtab->sh_size);
    if (elf->symbol_list == NULL)
        return;
    while ((void *)sym < (void *)(((char *)header + symtab->sh_offset) +
        symtab->sh_size)) {
        find_one_symbol(args, sym, elf, &total_nb_symb);
        sym++;
    }
    display_symbol(args, exec, elf, total_nb_symb);
}