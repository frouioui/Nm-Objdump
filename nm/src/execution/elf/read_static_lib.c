/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Read a static lib file (ar file)
*/

#include <ar.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "execution.h"
#include "execution_error.h"
#include "elf_reader.h"

static bool get_header(struct ar_hdr **ar, int fd)
{
    if (*ar == NULL) {
        *ar = calloc(1, sizeof(struct ar_hdr) + 1);
        if (*ar == NULL)
            return (false);
    }
    if (read(fd, *ar, sizeof(struct ar_hdr)) != sizeof(struct ar_hdr)) {
        free(*ar);
        return (false);
    }
    ((char *)*ar)[sizeof(struct ar_hdr)] = 0;
    if (memcmp((*ar)->ar_fmag, ARFMAG, strlen(ARFMAG))) {
        free(*ar);
        return (false);
    }
    return (true);
}

static bool get_data_header(struct ar_hdr *ar, int fd, unsigned int *size,
    char **header)
{
    if (ar == NULL)
        return (false);
    *size = atoi(ar->ar_size);
    if ((*header = calloc(1, sizeof(char) * (*size + 5))) == NULL)
        return (false);
    if ((read(fd, *header, *size)) != *size) {
        return (false);
    }
    return (*header ? true : false);
}

static bool check_ar(char **header, unsigned int *size, int fd)
{
    struct ar_hdr *ar = calloc(1, sizeof(struct ar_hdr) + 1);

    if (ar == NULL)
        return (false);
    if (get_header(&ar, fd) == false || get_data_header(ar, fd, size, header)
        == false) {
        return (false);
    }
    free(*header);
    *header = NULL;
    if (get_header(&ar, fd) == false || get_data_header(ar, fd, size, header)
        == false) {
        return (false);
    }
    free(ar);
    *header[*size] = '\0';
    return (true);
}

void get_name(elf_info_t *elf, char *header, unsigned int header_size)
{
    int i = 0;
    unsigned int size = 0;

    if (elf->path[i] == '/') {
        size = atoi(&elf->path[i + 1]);
        if (size < header_size)
            elf->path = &header[size];
    }
    while (elf->path[i] && elf->path[i] != '/')
        i++;
    elf->path[i] = '\0';
}

static bool get_content(int fd, argument_parser_t *args,
    info_ar_t *info, struct ar_hdr *ar)
{
    elf_info_t *elf = get_info_file(NULL, fd, ar->ar_name,
        (size_t)atoi(ar->ar_size));

    if (elf == NULL)
        return (false);
    get_name(elf, info->header, info->size);
    elf->arch = elf->header->e_ident[4] == ELFCLASS32 ? ARCH_32 : ARCH_64;
    get_section_header_address(elf);
    get_address_symbol(elf, info->exec);
    if (info->exec->error.type != NO_EXEC_ERROR)
        return (false);
    info->name = elf->path;
    printf("\n%s:\n", elf->path);
    if (elf->arch == ARCH_32) {
        exec_elf_32(args, info->exec, elf);
    } else if (elf->arch == ARCH_64) {
        exec_elf_64(args, info->exec, elf);
    }
    return (true);
}

void read_static_lib(elf_info_t *elf, argument_parser_t *args,
    execution_information_t *exec, char *filename)
{
    char *header = NULL;
    unsigned int ar_size = 0;
    struct ar_hdr *ar = NULL;
    info_ar_t info = {exec: exec, name: ""};

    if (check_ar(&header, &ar_size, exec->fd) == false)
        return;
    while (get_header(&ar, exec->fd) != false) {
        info.header = header;
        info.size = ar_size;
        if (get_content(exec->fd, args, &info, ar) == false) {
            printf("nm: %s: File format not recognized\n", info.name);
            printf("nm: %s: Malformated archive\n", filename);
            exit(84);
        }
    }
}