/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Main elf reader file
*/

#include <elf.h>
#include <string.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

bool is_magic_valid(Elf64_Ehdr *header)
{
    if (memcmp(header->e_ident, ELFMAG, SELFMAG) == 0) {
        return (true);
    }
    return (false);
}