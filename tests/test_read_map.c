/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** UT: Writing a map in an allocated buffer
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_malloc.h"
#include "tests/maps.h"

#include "bsq.h"

Test(read_map, regular_usage)
{
    str2c_t path = "UTMAP_10_10_D3.tmp";
    FILE *fp = fopen(path, "w+");
    str_t mapbuff = NULL;
    mapstat_t ms = {-1, {0}};

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_eq((count_t) read_map(&mapbuff, &ms), sizeof(UTMAP_10_10_D3));
    cr_assert_not_null(mapbuff);
    cr_expect_str_eq(mapbuff, UTMAP_10_10_D3);
    close(ms.fd);
}

Test(read_map, broken_malloc, .fini = fix_malloc)
{
    str2c_t path = "UTMAP_10_10_D3-no_malloc.tmp";
    FILE *fp = fopen(path, "w+");
    str_t mapbuff = NULL;
    mapstat_t ms = {-1, {0}};

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3, fp);
    cr_assert_not(open_map(path, &ms));
    break_malloc();
    cr_expect_eq(read_map(&mapbuff, &ms), -1);
    cr_expect_null(mapbuff);
    close(ms.fd);
}
