/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** UT: Opening a map
*/

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrap_open.h"

#include "bsq.h"

Test(open_map, existing_file)
{
    mapstat_t ms = {-1, {0}};

    cr_assert_not(close(open("./TEST_OPEN_MAP-1.tmp", O_CREAT)));
    cr_expect_not(open_map("./TEST_OPEN_MAP-1.tmp", &ms));
    cr_expect_neq(ms.fd, -1);
    cr_expect_not(close(ms.fd));
}

Test(open_map, invalid_file)
{
    mapstat_t ms = {-1, {0}};

    cr_expect(open_map("", &ms));
    cr_expect_eq(ms.fd, -1);
    cr_expect(close(ms.fd));
}

Test(open_map, broken_open, .fini = fix_open)
{
    mapstat_t ms = {-1, {0}};

    cr_assert_not(close(open("./TEST_OPEN_MAP-2.tmp", O_CREAT)));
    break_open();
    cr_expect(open_map("./TEST_OPEN_MAP-2.tmp", &ms));
    cr_expect_eq(ms.fd, -1);
}
