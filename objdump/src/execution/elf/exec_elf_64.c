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

// static bool find_one_symbol(argument_parser_t *args, Elf64_Sym *sym,
//     elf_info_t *elf, int *i)
// {
//     Elf64_Shdr *symtab = elf->symtab;
//     Elf64_Shdr *shdr = elf->shdr;
//     Elf64_Ehdr *header = elf->header;

//     if (sym->st_info != STT_FILE && sym->st_name > 0) {
//         elf->symbol_list[*i].type = guess_type_64(header, shdr, sym);
//         elf->symbol_list[*i].sym = sym;
//         if (sym->st_info == STT_SECTION && sym->st_shndx <= header->e_shnum &&
//             sym->st_name == 0) {
//             elf->symbol_list[*i].name = &STR_SEC[shdr[sym->st_shndx].sh_name];
//         } else {
//             elf->symbol_list[*i].name = &STR_SYMB[sym->st_name];
//         }
//         elf->symbol_list[*i].value = sym->st_value;
//         if ((void *)elf->symbol_list[*i].name > (void *)((char *)elf->header +
//             elf->size))
//             return (false);
//         (*i)++;
//     }
//     return (true);
// }

static void print_header_64(elf_info_t *elf, Elf64_Ehdr *header, int flag)
{
    printf("\n%s:     file format elf64-x86-64\n", elf->path);
    printf("architecture: %s, flags 0x%08x:\n", arch_string_64(header), flag);
    display_flags_64(header, flag);
    printf("\nstart address 0x%016lx\n\n", header->e_entry);
}

static int set_flag_file_type(Elf64_Ehdr *header)
{
    int flag = 0;

    header->e_type == ET_REL ? flag = 17 : 0;
    header->e_type == ET_EXEC ? flag = 274 : 0;
    header->e_type == ET_DYN ? flag = 336 : 0;
    return (flag);
}

static bool important_section(Elf64_Ehdr *header, Elf64_Shdr *shdr,
    unsigned int i)
{
    char non_important[11][30] = {".bss", ".symtab", ".shstrtab", ".strtab",
    ".rela.debug_line", ".rela.debug_aranges", ".rela.debug_info", ".tbss",
    ".rela.text", ".rela.eh_frame", "__libc_freeres_ptrs"};

    if (shdr[i].sh_size <= 0)
        return (false);
    for (unsigned int i = 0; i < 11; i++) {
        if (!strcmp(non_important[i], &STR_SEC[shdr[i].sh_name])) {
            return (false);
        }
    }
    return (true);
}

static void execute_one_paragraph(Elf64_Ehdr *header, Elf64_Shdr *shdr,
    unsigned int i, elf_info_t *elf)
{
    if (important_section(header, shdr, i) == true) {
        printf("Contents of section %s:\n", &STR_SEC[shdr[i].sh_name]);
    }
}

void exec_elf_64(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf)
{
    Elf64_Ehdr *header = elf->header;
    Elf64_Shdr *shdr = elf->shdr;
    int flag = set_flag_file_type(header);

    print_header_64(elf, header, flag);
    for (unsigned int i = 0; i < header->e_shnum; i++) {
        execute_one_paragraph(header, shdr, i, elf);
    }
}