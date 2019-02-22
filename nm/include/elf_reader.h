/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header of the elf function and struct
*/

#if !defined(_ELF_READER_H)
#define _ELF_READER_H

#include <elf.h>
#include "argument_parser.h"
#include "execution.h"

#define STR_SEC ((char *)header + shdr[header->e_shstrndx].sh_offset)
#define STR_SYMB ((char *)header + shdr[symtab->sh_link].sh_offset)

typedef struct info_ar_s {
    execution_information_t *exec;
    char *header;
    char *name;
    unsigned int size;
} info_ar_t;

enum arch_elf_file_e {
    ARCH_NOT_FOUND,
    ARCH_32,
    ARCH_64
};

typedef enum arch_elf_file_e arch_elf_file_t;

struct symbol_list_s {
    Elf64_Sym *sym;
    char *name;
    char type;
    unsigned int value;
};

typedef struct symbol_list_s symbol_list_t;

struct elf_info_s {
    bool static_lib;
    arch_elf_file_t arch;
    char *path;
    Elf64_Ehdr *header;
    Elf64_Shdr *shdr;
    Elf64_Shdr *symtab;
    size_t size;
    symbol_list_t *symbol_list;
};

typedef struct elf_info_s elf_info_t;

void read_elf(argument_parser_t *args, execution_information_t *exec);
elf_info_t *get_info_file(void *file, int fd, char *path, size_t size);
bool is_magic_valid(Elf64_Ehdr *header);
void get_address_symbol(elf_info_t *elf, execution_information_t *exec);
void exec_elf_64(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf_info);
void exec_elf_32(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf);
char guess_type_64(Elf64_Ehdr *header, Elf64_Shdr *shdr, Elf64_Sym *sym);
char guess_type_32(Elf32_Ehdr *header, Elf32_Shdr *shdr, Elf32_Sym *sym);
void display_symbol(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf, unsigned int nb_symbol);
void order_symbol_list(argument_parser_t *args, elf_info_t *elf,
    unsigned int nb_symbol);
void read_static_lib(elf_info_t *elf, argument_parser_t *args,
    execution_information_t *exec, char *filename);
void get_section_header_address(elf_info_t *elf);

#endif // _ELF_READER_H
