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


static void print_header_32(elf_info_t *elf, Elf32_Ehdr *header, int flag)
{
    printf("\n%s:     file format elf32-i386\n", elf->path);
    printf("architecture: %s, flags 0x%08x:\n", arch_string_32(header), flag);
    display_flags_32(header, flag);
    printf("\nstart address 0x%08x\n\n", header->e_entry);
}

static int set_flag_file_type(Elf32_Ehdr *header)
{
    int flag = 0;

    header->e_type == ET_REL ? flag = 17 : 0;
    header->e_type == ET_EXEC ? flag = 274 : 0;
    header->e_type == ET_DYN ? flag = 336 : 0;
    return (flag);
}

static bool important_section(Elf32_Ehdr *header, Elf32_Shdr *shdr,
    unsigned int i)
{
    char non_important[11][30] = {".bss", ".symtab", ".shstrtab", ".strtab",
    ".rela.debug_line", ".rela.debug_aranges", ".rela.debug_info", ".tbss",
    ".rela.text", ".rela.eh_frame", "__libc_freeres_ptrs"};

    if (shdr[i].sh_size <= 0)
        return (false);
    for (unsigned int j = 0; j < 11; j++) {
        if (!strcmp(non_important[j], &STR_SEC[shdr[i].sh_name])) {
            return (false);
        }
    }
    return (true);
}

static void execute_one_paragraph(Elf32_Ehdr *header, Elf32_Shdr *shdr,
    unsigned int i, elf_info_t *elf)
{
    unsigned int j = 0;

    if (important_section(header, shdr, i) == true) {
        printf("Contents of section %s:\n", &STR_SEC[shdr[i].sh_name]);
        j = shdr[i].sh_offset;
        while (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
            printf(" %04x ", (int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
            display_value_in_hexa((void *)header + j,
                shdr[i].sh_offset + shdr[i].sh_size - j);
            printf("\n");
            j += 16;
        }
    }
}

void exec_elf_32(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf)
{
    Elf32_Ehdr *header = (Elf32_Ehdr *)elf->header;
    Elf32_Shdr *shdr = (Elf32_Shdr *)elf->shdr;
    int flag = set_flag_file_type(header);

    print_header_32(elf, header, flag);
    for (unsigned int i = 0; i < header->e_shnum; i++) {
        execute_one_paragraph(header, shdr, i, elf);
    }
}