/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Read a static lib file (ar file)
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "execution.h"
#include "execution_error.h"
#include "elf_reader.h"

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