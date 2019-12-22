/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** solve_matrix.c -- No description
*/

#include <stdbool.h>
#include <sys/types.h>
#include "fox_define.h"
#include "fox_math.h"

#include "bsq.h"

__Anonnull static void update_bsq_position(mapdims_t *pos, uint size)
{
    if (BSQPOS.size >= size)
        return;
    BSQPOS.pos.x = pos->x;
    BSQPOS.pos.y = pos->y;
    BSQPOS.size = size;
}

__Anonnull static uint get_cell_value(
    mapdims_t *md, uint mtx[md->y][md->x], mapdims_t *pos)
{
    return N_MIN(
        N_MIN(
            pos->x ? mtx[pos->y][pos->x - 1] : 0,
            pos->y ? mtx[pos->y - 1][pos->x] : 0),
        pos->x && pos->y ? mtx[pos->y - 1][pos->x - 1] : 0)
        + 1;
}

__Anonnull static bool set_line(
    mapdims_t *md, uint mtx[md->y][md->x], mapdims_t *pos, str2c_t *mapbuff)
{
    for (pos->x = 0; pos->x < md->x; pos->x += 1) {
        switch (*(*mapbuff)++) {
            case '.':
                mtx[pos->y][pos->x] = get_cell_value(md, mtx, pos);
                update_bsq_position(pos, mtx[pos->y][pos->x]);
                continue;
            case 'o': mtx[pos->y][pos->x] = 0; continue;
            default: return true;
        }
    }
    return !SUCCESS_IF_DIFF(*(*mapbuff)++, '\n');
}

__Anonnull bool solve_matrix(
    mapdims_t *md, uint mtx[md->y][md->x], str2c_t mapbuff)
{
    mapdims_t pos;

    for (pos.y = 0; pos.y < md->y; pos.y += 1)
        if (set_line(md, mtx, &pos, &mapbuff))
            return true;
    return false;
}
