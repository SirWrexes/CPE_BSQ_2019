/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Read a map into a dynamically allocated buffer
*/

#include <unistd.h>
#include <malloc.h>

#include "fox_define.h"

#include "bsq.h"

__Anonnull
extern inline scount_t read_map(str_t *buffptr, mapstat_t *ms)
{
    *buffptr = malloc(ms->stat.st_size * sizeof(**buffptr));
    if (*buffptr == NULL)
        return -1;
    return read(ms->fd, *buffptr, ms->stat.st_size);
}
