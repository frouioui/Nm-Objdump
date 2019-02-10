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
    symbol_list_t *symbol_list;
};

typedef struct elf_info_s elf_info_t;

void read_elf(argument_parser_t *args, execution_information_t *exec);
elf_info_t *get_info_file(void *file, int fd, char *path);
bool is_magic_valid(Elf64_Ehdr *header);
void get_address_symbol(elf_info_t *elf, execution_information_t *exec);
void exec_elf_64(argument_parser_t *args, execution_information_t *exec,
    elf_info_t *elf_info);
char guess_type_64(Elf64_Ehdr *header, Elf64_Shdr *shdr, Elf64_Sym *sym);

#endif // _ELF_READER_H
