/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Try opening a map file
*/

#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "fox_define.h"

#include "bsq.h"

__Anonnull extern inline bool open_map(str2c_t path, mapstat_t *ms)
{
    ms->fd = open(path, O_RDONLY);
    return SUCCESS_IF_DIFF(ms->fd, -1)
        || SUCCESS_IF_DIFF(stat(path, &ms->stat), -1);
}
