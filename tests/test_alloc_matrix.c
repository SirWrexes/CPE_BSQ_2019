/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_alloc_matrix.c -- No description
*/

#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "tests/maps.h"

#include "bsq.h"

__Anonnull
static bool test_alloc_matrix(mapdims_t *md)
{
    bool r;
    uint (*mtxp)[md->y][md->x] = NULL;


    r = alloc_matrix(md, &mtxp);
    if (r == false)
        free(mtxp);
    return r;
}

Test(alloc_matrix, regular_usage)
{
    str2c_t path = "UTMAP_6_6_D25-alloctest.tmp";
    FILE *fp = fopen(path, "w+");
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_6_6_D25, fp);
    cr_assert_not(open_map(path, &ms)
        || !read_map(&mapbuff, &ms)
        || get_dimensions(&md, &ms, mapbuff));
    cr_assert_not(test_alloc_matrix(&md));
}

Test(alloc_matrix, broken_malloc, .fini = fix_malloc)
{
    str2c_t path = "UTMAP_6_6_D25-alloctest_fail.tmp";
    FILE *fp = fopen(path, "w+");
    mapdims_t md = {.x = 0, .y = 0};
    mapstat_t ms = {-1, {0}};
    str_t mapbuff = NULL;

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_6_6_D25, fp);
    cr_assert_not(open_map(path, &ms)
        || !read_map(&mapbuff, &ms)
        || get_dimensions(&md, &ms, mapbuff));
    break_malloc();
    cr_assert(test_alloc_matrix(&md));
}
