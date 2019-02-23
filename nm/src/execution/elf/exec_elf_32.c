/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Exec the given file for 64bits
*/

#include <elf.h>
#include <string.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static symbol_list_t *new_symbol_list(unsigned int size)
{
    symbol_list_t *new = NULL;

    new = calloc(1, sizeof(symbol_list_t) * size);
    return (new);
}

static bool find_one_symbol(argument_parser_t *args, Elf32_Sym *sym,
    elf_info_t *elf, int *i)
{
    Elf32_Shdr *symtab = (Elf32_Shdr *)elf->symtab;
    Elf32_Shdr *shdr = (Elf32_Shdr *)elf->shdr;
    Elf32_Ehdr *header = (Elf32_Ehdr *)elf->header;

    if (sym->st_info != STT_FILE && sym->st_name > 0) {
        elf->symbol_list[*i].type = guess_type_32(header, shdr, sym);
        elf->symbol_list[*i].sym = (Elf64_Sym *)sym;
        if (sym->st_info == STT_SECTION && sym->st_shndx <= header->e_shnum &&
            sym->st_name == 0) {
            elf->symbol_list[*i].name = &STR_SEC[shdr[sym->st_shndx].sh_name];
        } else {
            elf->symbol_list[*i].name = &STR_SYMB[sym->st_name];
        }
        elf->symbol_list[*i].value = sym->st_value;
        if ((void *)elf->symbol_list[*i].name > (void *)((char *)elf->header +
            elf->size))
            return (false);
        (*i)++;
    }
    return (true);
}

void exec_elf_32(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf)
{
    unsigned int total_nb_symb = 0;
    Elf32_Ehdr *header = (Elf32_Ehdr *)elf->header;
    Elf32_Shdr *symtab = (Elf32_Shdr *)elf->symtab;
    Elf32_Sym *sym = (Elf32_Sym *)((char *)header + symtab->sh_offset);

    elf->symbol_list = new_symbol_list(symtab->sh_size);
    if (elf->symbol_list == NULL)
        return;
    while ((void *)sym < (void *)(((char *)header + symtab->sh_offset) +
        symtab->sh_size)) {
        if (find_one_symbol(args, sym, elf, &total_nb_symb) == false) {
            exec->error = new_execution_error(EXEC_TRUNCATED,
                strcat(elf->path, ": File format not recognized"), NULL);
            return;
        }
        sym++;
    }
    display_symbol(args, exec, elf, total_nb_symb);
}