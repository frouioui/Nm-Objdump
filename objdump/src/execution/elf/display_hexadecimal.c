/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Source file of the display_value_in_hexa function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void handle_print(unsigned int j, unsigned int size, uint8_t *i)
{
    if (j < size) {
        if (i[j] >= ' ' && i[j] <= '~')
            printf("%c", i[j]);
        else
            printf(".");
    } else {
        printf(" ");
    }
}

void display_value_in_hexa(void *data, unsigned int size)
{
    uint8_t *i = data;
    unsigned int four = 0;
    unsigned int j = 0;

    for (j = 0; j < 16; j++) {
        if (j < size) {
            printf("%02x", i[j]);
        } else {
            printf("  ");
        }
        if (!((j + 1) % 4))
            printf(" ");
    }
    printf(" ");
    for (j = 0; j < 16; j++) {
        handle_print(j, size, i);
    }
}