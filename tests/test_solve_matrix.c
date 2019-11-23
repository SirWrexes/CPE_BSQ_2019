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

__Anonnull
static bool test_solve_matrix(mapdims_t *md, str2c_t buff)
{
    uint (*mtxp)[md->y][md->x] = NULL;
    bool r = alloc_matrix(md, &mtxp);

    if (r)
        return true;
    r = solve_matrix(md, *mtxp, buff + fox_unumsize(md->y) + 1);
    for (uint y = 0; !r && y < md->y; y += 1)
        for (uint x = 0; !r && x < md->x; x += 1)
            r = (UTMTX_6_6_D25[y][x] == (*mtxp)[y][x]);
    for (uint y = 0; !r && y < md->y; y += 1)
        for (uint x = 0; !r && x < md->x; x += 1)
            r = (UTMTX_6_6_D25[y][x] == (*mtxp)[y][x]);
    return r;
}

Test(solve_matrix, regular_usage)
{
    str2c_t path = "UTMAP_6_6_D25-solvetest.tmp";
    FILE *fp = fopen(path, "w+");
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_6_6_D25, fp);
    cr_assert_not(open_map(path, &ms)
        || SUCCEED_IF_DIFF(read_map(&mapbuff, &ms), -1)
        || get_dimensions(&md, &ms, mapbuff));
    md.x += 1;
    cr_assert_not(test_solve_matrix(&md, mapbuff));
}

Test(solve_matrix, invalid_char)
{
    str2c_t path = "UTMAP_6_6_D25-invalid_char.tmp";
    FILE *fp = fopen(path, "w+");
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_6_6_INVALIDCHAR, fp);
    cr_assert_not(open_map(path, &ms)
        || SUCCEED_IF_DIFF(read_map(&mapbuff, &ms), -1)
        || get_dimensions(&md, &ms, mapbuff));
    md.x += 1;
    cr_assert_not(test_solve_matrix(&md, mapbuff));
}
