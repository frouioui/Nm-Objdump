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

static void print_header_64(elf_info_t *elf, Elf64_Ehdr *header, int flag)
{
    printf("\n%s:     file format elf64-x86-64\n", elf->path);
    printf("architecture: %s, flags 0x%08x:\n", arch_string_64(header), flag);
    display_flags_64(header, flag);
    printf("\nstart address 0x%016lx\n\n", header->e_entry);
}

static int set_flag_file_type(Elf64_Ehdr *header)
{
    int flags = 0x0000;

    if (header->e_type == ET_EXEC)
        flags += EXEC_P + D_PAGED;
    else if (header->e_type == ET_DYN)
        flags += DYNAMIC + D_PAGED;
    if (header->e_type == ET_REL && header->e_type != ET_EXEC &&
        header->e_type != ET_DYN)
        flags += HAS_RELOC;
    flags += has_syms(header);
    return (flags);
}

static bool important_section(Elf64_Ehdr *header, Elf64_Shdr *shdr,
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

static void execute_one_paragraph(Elf64_Ehdr *header, Elf64_Shdr *shdr,
    unsigned int i, elf_info_t *elf)
{
    unsigned int j = 0;
    int diff = 0;

    if (important_section(header, shdr, i) == true) {
        printf("Contents of section %s:\n", &STR_SEC[shdr[i].sh_name]);
        j = shdr[i].sh_offset;
        diff = get_difference_size(shdr, i);
        while (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
            printf(" %0*x ", diff + 4, (int)(shdr[i].sh_addr + j -
                shdr[i].sh_offset));
            display_value_in_hexa((void *)header + j,
                shdr[i].sh_offset + shdr[i].sh_size - j);
            printf("\n");
            j += 16;
        }
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