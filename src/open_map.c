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

#include "bsq.h"

__Anonnull
extern inline bool open_map(str2c_t path, mapstat_t *ms)
{
    ms->fd = open(path, O_RDONLY);
    if (ms-> fd != -1)
        return stat(path, &ms->stat) == -1;
    return true;
}
