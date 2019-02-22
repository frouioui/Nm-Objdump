/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Set the global variable of the argument struct
*/

const unsigned int NUMBER_OF_LONG_FLAG = 10;

const unsigned int NUMBER_OF_SHORT_FLAG = 9;

const char long_flags[10][20] = {{"--print-file-name"}, {"--debug-syms"},
    {"--line-numbers"}, {"--numeric-sort"}, {"--no-sort"}, {"--reverse-sort"},
    {"--print-size"}, {"--undefined-only"}, {"--defined-only"}, {"--help"}};

const char short_flags[9][2] = {{'A', 'o'}, {'a', '\0'}, {'l', '\0'},
    {'n', 'v'}, {'p', '\0'}, {'r', '\0'}, {'S', '\0'}, {'u', '\0'},
    {'h', '\0'}};