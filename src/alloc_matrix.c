/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Alloc a matrix for bsq algorithm
*/

#include <stdbool.h>
#include <sys/types.h>
#include <malloc.h>

#include "fox_define.h"

#include "bsq.h"

__Anonnull
extern inline bool alloc_matrix(mapdims_t *md, uint (**mtxp)[md->y][md->x])
{
    *mtxp = malloc(sizeof(**mtxp));
    return SUCCEED_IF_DIFF(*mtxp, NULL);
}
