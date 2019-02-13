/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Order the given symbols
*/

#include <elf.h>
#include <string.h>
#include <stdio.h>
#include "argument_parser.h"
#include "execution.h"
#include "elf_reader.h"

static char *ignore_underscore(char *name)
{
    if (name[0] == '_' && name[1] == '_') {
        return (strdup(name + 2));
    } else if (name[0] == '_') {
        return (strdup(name + 1));
    }
    return (strdup(name));
}

static void weight_special_char(char *str1, char *str2)
{
    for (unsigned int i = 0; str1[i]; i++) {
        if (str1[i] == '_')
            str1[i] = '}';
        if (str1[i] == '@')
            str1[i] = '~';
    }
    for (unsigned int i = 0; str2[i]; i++) {
        if (str2[i] == '_')
            str2[i] = '}';
        if (str2[i] == '@')
            str2[i] = '~';
    }
}

static void swap_name(unsigned int j, elf_info_t *elf)
{
    symbol_list_t temp = {0};
    char *cmp1 = NULL;
    char *cmp2 = NULL;

    cmp1 = ignore_underscore(elf->symbol_list[j].name);
    cmp2 = ignore_underscore(elf->symbol_list[j + 1].name);
    weight_special_char(cmp1, cmp2);
    if (strcasecmp(cmp1, cmp2) > 0) {
        temp = elf->symbol_list[j];
        elf->symbol_list[j] = elf->symbol_list[j + 1];
        elf->symbol_list[j + 1] = temp;
    }
    free(cmp1);
    free(cmp2);
}

void order_symbol_list(argument_parser_t *args, elf_info_t *elf,
    unsigned int nb_symbol)
{
    for (unsigned int i = 1; i < nb_symbol; i++) {
        for (unsigned int j = 0; j < nb_symbol - i; j++) {
            swap_name(j, elf);
        }
    }
}