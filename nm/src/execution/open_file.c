/*
** EPITECH PROJECT, 2019
** PSU_NmObjdump
** File description:
** Open the file and fill the exec struct
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "execution.h"

static char *new_no_such_file_error(char *path)
{
    char *str = calloc(1, sizeof(char) *
        (strlen(path) + 2 + strlen("'': No such file")));

    str[0] = '\'';
    str = strcat(str, path);
    str = strcat(str, "': No such file");
    return (str);
}

static char *new_file_is_dir_error(char *path)
{
    char *str = calloc(1, sizeof(char) *
        (strlen(path) + 2 + strlen("Warning: '': is a directory")));

    str = strcat(str, "Warning: '");
    str = strcat(str, path);
    str = strcat(str, "': is a directory");
    return (str);
}

void open_file(execution_information_t *exec, char *path)
{
    int fd = 0;
    struct stat file_info;

    stat(path, &file_info);
    if (S_ISDIR(file_info.st_mode)) {
        exec->fd = -1;
        exec->error = new_execution_error(EXEC_FILE_IS_DIR,
            new_file_is_dir_error(path), "open_file");
        return;
    }
    if (path == NULL)
        return;
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        exec->fd = -1;
        exec->error = new_execution_error(EXEC_NO_SUCH_FILE,
            new_no_such_file_error(path), "open_file");
        return;
    }
    exec->fd = fd;
}
