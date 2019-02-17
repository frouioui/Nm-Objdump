/*
** EPITECH PROJECT, 2019
** PSU_objdump
** File description:
** Get the arch in a char *
*/

#include <elf.h>
#include <string.h>

char *arch_string_64(Elf64_Ehdr *header)
{
    if (header->e_machine == EM_386) {
        return (strdup("i386"));
    } else if (header->e_machine == EM_X86_64) {
        return (strdup("i386:x86-64"));
    }
    return (strdup("Unknown"));
}