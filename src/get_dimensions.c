/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Extract dimensions from the read file
*/

#include <stdbool.h>

#include "fox_define.h"
#include "fox_std.h"
#include "fox_math.h"

#include "bsq.h"

__Anonnull
static size_t linelen(str_t s)
{
    size_t i;

    for (i = 0; *s != '\n' && *s++ != '\0'; i += 1);
    return i;
}

__Anonnull
bool get_dimensions(mapdims_t *md, mapstat_t *ms, str_t mapbuff)
{
    if (!CHAR_IS_NUM(*mapbuff))
        return true;
    md->y = fox_strtol(mapbuff, &mapbuff);
    if (*mapbuff++ != '\n')
        return true;
    md->x = linelen(mapbuff);
    return (md->x + 1) * md->y
        != (ms->stat.st_size / sizeof(char) - (fox_unumsize(md->y) + 1));
}
