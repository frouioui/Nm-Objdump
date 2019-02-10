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

struct elf_info_s {
    bool static_lib;
    arch_elf_file_t arch;
    char *path;
    Elf64_Ehdr *header;
    Elf64_Shdr *shdr;
    Elf64_Shdr *symtab;
};

typedef struct elf_info_s elf_info_t;

void read_elf(argument_parser_t *args, execution_information_t *exec);
elf_info_t *get_info_file(void *file, int fd, char *path);
bool is_magic_valid(Elf64_Ehdr *header);

#endif // _ELF_READER_H
