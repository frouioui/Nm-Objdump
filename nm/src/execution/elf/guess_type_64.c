/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** guess the type of the symbol for 64bits
*/

#include <elf.h>

static char find_type(Elf64_Shdr *shdr, Elf64_Sym *sym)
{
    char c = 0;

    sym->st_shndx == SHN_UNDEF ? c = 'U' : 0;
    sym->st_shndx == SHN_ABS ? c = 'A' : 0;
    sym->st_shndx == SHN_COMMON ? c = 'C' : 0;
    shdr[sym->st_shndx].sh_type == SHT_NOBITS &&
    shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE) ?
        c = 'B' : 0;
    shdr[sym->st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym->st_shndx].sh_flags == SHF_ALLOC ? c = 'R' : 0;
    shdr[sym->st_shndx].sh_type == SHT_PROGBITS &&
    shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE) ? c = 'D' : 0;
    shdr[sym->st_shndx].sh_type == SHT_PROGBITS &&
    shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR) ? c = 'T' : 0;
    shdr[sym->st_shndx].sh_type == SHT_DYNAMIC ? c = 'D' : 0;
    c == 0 ? c = '?' : 0;
    return (c);
}

char guess_type_64(Elf64_Ehdr *header, Elf64_Shdr *shdr, Elf64_Sym *sym)
{
    char c;

    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK)
        c = (sym->st_shndx == SHN_UNDEF) ? 'w' : 'W';
    else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK &&
        ELF64_ST_TYPE(sym->st_info) == STT_OBJECT)
        c = (sym->st_shndx == SHN_UNDEF) ? 'v' : 'V';
    else
        c = find_type_2(shdr, sym);
    if (c == '?' &&
        (strcmp(&((char *)header + shdr[header->e_shstrndx].sh_offset)
        [shdr[sym->st_shndx].sh_name], ".init_array") ||
        strcmp(&((char *)header + shdr[header->e_shstrndx].sh_offset)
        [shdr[sym->st_shndx].sh_name], ".fini_array")))
        c = 'T';
    if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL && c != '?')
        c += 32;
    return (c);
}