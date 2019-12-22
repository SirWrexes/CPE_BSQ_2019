/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** UT: Getting and doing a preemptive check of the map's dimensions
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

#include "bsq.h"

Test(get_dimentsions, regular_usage)
{
    str2c_t path = "UTMAP_10_10_D3-dimensions-OK.tmp";
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t buffer = NULL;
    FILE *fp = fopen(path, "w+");

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_neq(read_map(&buffer, &ms), -1);
    cr_expect_not(get_dimensions(&md, &ms, buffer));
    close(ms.fd);
}

Test(get_dimentsions, invalid_line_one_a)
{
    str2c_t path = "UTMAP_10_10_D3-invalid_l1-A.tmp";
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t buffer = NULL;
    FILE *fp = fopen(path, "w+");

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3_INVALIDL1_A, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_neq(read_map(&buffer, &ms), -1);
    cr_expect(get_dimensions(&md, &ms, buffer));
    close(ms.fd);
}

Test(get_dimentsions, invalid_line_one_b)
{
    str2c_t path = "UTMAP_10_10_D3-invalid_l1-B.tmp";
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t buffer = NULL;
    FILE *fp = fopen(path, "w+");

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3_INVALIDL1_B, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_neq(read_map(&buffer, &ms), -1);
    cr_expect(get_dimensions(&md, &ms, buffer));
    close(ms.fd);
}

Test(get_dimentsions, invalid_char_count)
{
    str2c_t path = "UTMAP_10_10_D3-invalid_cc.tmp";
    mapstat_t ms = {-1, {0}};
    mapdims_t md = {.x = 0, .y = 0};
    str_t buffer = NULL;
    FILE *fp = fopen(path, "w+");

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3_INVALIDCC, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_neq(read_map(&buffer, &ms), -1);
    cr_expect(get_dimensions(&md, &ms, buffer));
    close(ms.fd);
}
