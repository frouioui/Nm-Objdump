/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Get difference between two int
*/

#include <elf.h>
#include <string.h>
#include <stdio.h>
#include "elf_reader.h"
#include "execution.h"
#include "parser_error.h"

static int get_len_int(int nb)
{
	int result = nb;
	int i = 0;

	while (result > 0) {
		result = result / 10;
		i++;
	}
	return (i);
}

static int get_len_hexa(int nb)
{
    int size = get_len_int(nb);
    char *str = calloc(1, sizeof(char) * size + 1);

    if (str == NULL)
        return (0);
    sprintf(str, "%x", nb);
    size = strlen(str);
    free(str);
    return (size);
}

int get_difference_size_32(Elf32_Shdr *shdr, unsigned int i)
{
    int extra = 0;
    int small = 0;
    int big = 0;
    int temp = 0;
    unsigned int j = 0;

    j = shdr[i].sh_offset;
    if (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
        small = get_len_hexa((int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
        big = small;
        j += 16;
    }
    while (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
        temp = get_len_hexa((int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
        if (temp > big)
            big = temp;
        j += 16;
    }
    if (big <= 4)
        return (0);
    return (big - small);
}

int get_difference_size(Elf64_Shdr *shdr, unsigned int i)
{
    int extra = 0;
    int small = 0;
    int big = 0;
    int temp = 0;
    unsigned int j = 0;

    j = shdr[i].sh_offset;
    if (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
        small = get_len_hexa((int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
        big = small;
        j += 16;
    }
    while (j < (unsigned int)(shdr[i].sh_size + shdr[i].sh_offset)) {
        temp = get_len_hexa((int)(shdr[i].sh_addr + j - shdr[i].sh_offset));
        if (temp > big)
            big = temp;
        j += 16;
    }
    if (big <= 4)
        return (0);
    return (big - small);
}