/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** solve_1d.c -- No description
*/

#include "fox_define.h"
#include "fox_io.h"
#include "fox_string.h"

__Anonnull __AalwaysILext bool solve_1d(str_t mapbuff)
{
    str_t out = NULL;

    mapbuff += fox_strspn(mapbuff, STR_NUMERIC "\n");
    out = mapbuff;
    mapbuff += fox_strspn(mapbuff, "o\n");
    switch (*mapbuff) {
        case '.':
            *mapbuff++ = 'x';
            if (*(mapbuff + fox_strspn(mapbuff, "o.\n")) != '\0')
                return true;
            __Afallthrough;
        default: fox_putstr(out); return false;
    }
}
