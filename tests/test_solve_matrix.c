/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_fill_matrix.c -- No description
*/

#include <stdbool.h>
#include "fox_math.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

#include "bsq.h"

__Anonnull static bool test_matrix(mapdims_t *md, str_t mapbuff)
{
    uint(*mtxp)[md->y][md->x] = NULL;
    bool b = false;

    if (alloc_matrix(md, &mtxp)
        || solve_matrix(md, *mtxp, mapbuff + fox_unumsize(md->y) + 1))
        return true;
    for (uint y = 0; !b && y < md->y; y += 1)
        for (uint x = 0; !b && x < md->x; x += 1)
            b = (UTMTX_6_6_D25[y][x] != (*mtxp)[y][x]);
    return b;
}

__Anonnull static bool write_map_file(str2c_t path, const char map[44])
{
    FILE *fp = fopen(path, "w+");

    if (fp == NULL || fwrite(map, sizeof(*map), strlen(map), fp) != strlen(map)
        || fclose(fp))
        return true;
    return false;
}

Test(solve_matrix, regular_usage)
{
    str2c_t path = "UTMAP_6_6_D25-solvetest.tmp";
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not(write_map_file(path, UTMAP_6_6_D25));
    cr_assert_not(open_map(path, &ms));
    cr_assert(read_map(&mapbuff, &ms));
    cr_assert_not(get_dimensions(&md, &ms, mapbuff));
    cr_assert_not(write_map_file(path, UTMAP_6_6_D25));
    cr_assert_not(test_matrix(&md, mapbuff));
}

Test(solve_matrix, invalid_char)
{
    str2c_t path = "UTMAP_6_6_D25-invalid_char.tmp";
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not(write_map_file(path, UTMAP_6_6_INVALIDCHAR));
    cr_assert_not(open_map(path, &ms));
    cr_assert(read_map(&mapbuff, &ms));
    cr_assert_not(get_dimensions(&md, &ms, mapbuff));
    cr_assert_not(write_map_file(path, UTMAP_6_6_D25));
    cr_assert(test_matrix(&md, mapbuff));
}
