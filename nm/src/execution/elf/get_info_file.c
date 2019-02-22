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

static Elf64_Ehdr *new_static_lib_elf(unsigned int size, int fd)
{
    Elf64_Ehdr *header = malloc(1 * (size + 1));

    if (header == NULL)
        return (NULL);
    if (read(fd, header, size) != size)
        return (NULL);
    ((char *)header)[size] = 0;
    if (memcmp(header->e_ident, ELFMAG, strlen(ELFMAG)))
        return (NULL);
    return (header);
}

elf_info_t *get_info_file(void *file, int fd, char *path, size_t size)
{
    elf_info_t *info = malloc(sizeof(elf_info_t));
    unsigned int arch = 0;

    if (info == NULL)
        return (NULL);
    if (file == NULL) {
        if (size < sizeof(Elf64_Ehdr))
            return (NULL);
        info->header = new_static_lib_elf(size, fd);
        if (info->header == NULL)
            return (NULL);
        info->static_lib = true;
    } else {
        info->header = file;
        info->static_lib = is_static_lib(fd);
    }
    info->arch = get_arch(info->header);
    info->path = path;
    info->size = size;
    return (info);
}