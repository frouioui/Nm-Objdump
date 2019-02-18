/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Display the flag for 64 bits
*/

#include <elf.h>
#include "elf_reader.h"

void display_flags_32(Elf32_Ehdr *header, int flag)
{
    bool first = true;
    flags_objdump_t flags[10] = {{BFD_NO_FLAGS, BFD_NO_FLAGS_STR}, {HAS_RELOC,
    HAS_RELOC_STR}, {EXEC_P, EXEC_P_STR}, {HAS_LINENO, HAS_LINENO_STR},
    {HAS_DEBUG, HAS_DEBUG_STR}, {HAS_SYMS, HAS_SYMS_STR}, {HAS_LOCALS,
    HAS_LOCALS_STR}, {DYNAMIC, DYNAMIC_STR}, {WP_TEXT, WP_TEXT_STR}, {D_PAGED,
    D_PAGED_STR}};

    for (unsigned int i = 0; i < 10; i++) {
        if (flag & flags[i].type) {
            first == false ? printf(", ") : 0;
            first = false;
            printf("%s", flags[i].value);
        }
    }
}