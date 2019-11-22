/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** UT: Getting and doing a preemptive check of the map's dimensions
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

#include "bsq.h"

Test(get_dimentsions, regular_usage)
{
    str2c_t path = "UTMAP_10_10_D3-dimensions-OK.tmp";
    mapstat_t ms = {-1, {0}};
    mapdims_t md = { .x = 0, .y = 0 };
    str_t buffer = NULL;
    FILE *fp = fopen(path, "w+");

    cr_assert_not_null(fp);
    ASSERT_FWRITE_MAP(UTMAP_10_10_D3, fp);
    cr_assert_not(open_map(path, &ms));
    cr_assert_neq(read_map(&buffer, &ms), -1);
    cr_expect_not(get_dimensions(&md, &ms, buffer));
    fclose(fp);
    close(ms.fd);
}
