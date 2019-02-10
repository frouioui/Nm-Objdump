/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Header of the error execution function and struct
*/

#if !defined(_ERROR_EXECUTION_H)
#define _ERROR_EXECUTION_H

enum execution_error_type_e {
    NO_EXEC_ERROR,
    EXEC_INTERNAL_ERROR_MEMORY,
    EXEC_NO_SUCH_FILE,
    EXEC_FILE_IS_DIR,
    EXEC_FILE_IS_NOT_ORDINARY
};

typedef enum execution_error_type_e execution_error_type_t;

struct execution_error_s {
    execution_error_type_t type;
    char *message;
    char *where;
};

typedef struct execution_error_s execution_error_t;

execution_error_t new_execution_error(execution_error_type_t type, char *msg,
    char *where);

#endif // _ERROR_EXECUTION_H
