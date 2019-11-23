/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** Main source
*/

#include <stdlib.h>
#include <unistd.h>

#include "fox_io.h"
#include "fox_math.h"

#include "bsq.h"

__Anonnull
static bool find_bsq(mapdims_t *md, str_t mapbuff, mapstat_t *ms)
{
    uint(*mtxp)[md->y][md->x] = NULL;
    bsqdata_t bsq;
    uint offset = (fox_unumsize(md->y) + 1) * sizeof(char);

    mapbuff += offset;
    if (alloc_matrix(md, &mtxp) || solve_matrix(md, *mtxp, mapbuff))
        return true;
    bsq.size = BSQPOS.size;
    bsq.pos.x = BSQPOS.pos.x + 1 - BSQPOS.size;
    bsq.pos.y = BSQPOS.pos.y + 1 - BSQPOS.size;
    for (uint sy = 0; sy < bsq.size; sy += 1)
        for (uint sx = 0; sx < bsq.size; sx += 1)
            *(mapbuff + (bsq.pos.y + sy) * (md->x + 1) + bsq.pos.x + sx) = 'x';
    write(1, mapbuff, ms->stat.st_size / sizeof(*mapbuff) - offset);
    free(mtxp);
    free(mapbuff - offset);
    return false;
}

int main(int ac, char **av)
{
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t mapbuff = NULL;

    if (ac != 2
    || open_map(av[1], &ms)
    || (count_t) read_map(&mapbuff, &ms) != ms.stat.st_size / sizeof(char)
    || get_dimensions(&md, &ms, mapbuff))
        return 84;
    if (md.x == 1 || md.x == 1)
        return solve_1d(mapbuff) * 84;
    else {
        close(ms.fd);
        return find_bsq(&md, mapbuff, &ms) * 84;
    }
}
