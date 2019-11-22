/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** Main source
*/

#include <stdlib.h>

#include "bsq.h"

int main(int ac, char **av)
{
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t mapbuff = NULL;

    if (ac != 2
    || open_map(av[1], &ms)
    || !read_map(&mapbuff, &ms)
    || get_dimensions(&md, &ms, mapbuff))
        return 84;
    if (md.x == 1 || md.x == 1)
        return solve_1d(mapbuff) * 84;
    return EXIT_SUCCESS;
}
