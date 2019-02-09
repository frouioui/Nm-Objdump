/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Get the arch of the given binary
*/

#include <elf.h>
#include <ar.h>
#include <unistd.h>
#include <string.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static bool is_static_lib(int fd)
{
    char magic_ar[SARMAG];

    if (read(fd, magic_ar, SARMAG) != SARMAG)
        return (false);
    if (strncmp(magic_ar, ARMAG, SARMAG))
        return (false);
    return (true);
}

static arch_elf_file_t get_arch(Elf64_Ehdr *elf)
{
    unsigned int arch = elf->e_ident[EI_CLASS];

    if (arch == ELFCLASS32) {
        return (ARCH_32);
    } else if (arch == ELFCLASS64) {
        return (ARCH_64);
    }
    return (ARCH_NOT_FOUND);
}

elf_info_t *get_info_file(void *file, int fd)
{
    elf_info_t *info = malloc(sizeof(elf_info_t));
    Elf64_Ehdr *elf = file;
    unsigned int arch = 0;

    if (info == NULL)
        return (NULL);
    info->header = file;
    info->arch = get_arch(info->header);
    info->static_lib = is_static_lib(fd);
    return (info);
}