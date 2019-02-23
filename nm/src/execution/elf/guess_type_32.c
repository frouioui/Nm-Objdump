/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** guess the type of the symbol for 32bits
*/

#include <elf.h>
#include <string.h>

static char find_type(Elf32_Shdr *shdr, Elf32_Sym *sym)
{
    char c = 0;

    if (sym->st_shndx > 50000)
        return (c);
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

static char check_week_unique_object(Elf32_Sym *sym)
{
    char c = 0;

    if (ELF32_ST_BIND(sym->st_info) == STB_WEAK &&
                                ELF32_ST_TYPE(sym->st_info) == STT_OBJECT)
        c = (sym->st_shndx == SHN_UNDEF) ? 'v' : 'V';
    if (c == 0 && ELF32_ST_BIND(sym->st_info) == STB_WEAK)
        c = (sym->st_shndx == SHN_UNDEF) ? 'w' : 'W';
    if (c == 0 && ELF32_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        c = 'u';
    return (c);
}

char guess_type_32(Elf32_Ehdr *header, Elf32_Shdr *shdr, Elf32_Sym *sym)
{
    char c;

    c = check_week_unique_object(sym);
    if (c == 0)
        c = find_type(shdr, sym);
    if (c == '?' &&
        (strcmp(&((char *)header + shdr[header->e_shstrndx].sh_offset)
        [shdr[sym->st_shndx].sh_name], ".init_array") ||
        strcmp(&((char *)header + shdr[header->e_shstrndx].sh_offset)
        [shdr[sym->st_shndx].sh_name], ".fini_array")))
        c = 'T';
    if (ELF32_ST_BIND(sym->st_info) == STB_LOCAL && c != '?')
        c += 32;
    return (c);
}