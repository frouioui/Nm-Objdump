/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header file containing all the error
*/

#if !defined(_PARSER_ERROR_H)
#define _PARSER_ERROR_H

enum error_parser_e {
    NO_ERROR_PARSER,
    INVALID_FLAG,
    INVALID_SYNTAX
};

typedef enum error_parser_e error_parser_t;

struct error_parser_info_s {
    error_parser_t type;
    char *message;
};

typedef struct error_parser_info_s error_parser_info_t;

#endif // _PARSER_ERROR_H
