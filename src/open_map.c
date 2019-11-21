/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Try opening a map file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "fox_define.h"

__nonnull
extern inline bool open_map(str2c_t path, int *fd)
{
    *fd = open(path, O_RDONLY);
    return (*fd == -1);
}
