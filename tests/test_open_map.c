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
    int fd = -1;

    cr_assert_not(close(open("./TEST_OPEN_MAP-1.tmp", O_CREAT)));
    cr_expect_not(open_map("./TEST_OPEN_MAP-1.tmp", &fd));
    cr_expect_neq(fd, -1);
    cr_expect_not(close(fd));
}

Test(open_map, invalid_file)
{
    int fd = -1;

    cr_expect(open_map("", &fd));
    cr_expect_eq(fd, -1);
    cr_expect(close(fd));
}

Test(open_map, broken_open, .fini = fix_open)
{
    int fd = -1;

    cr_assert_not(close(open("./TEST_OPEN_MAP-2.tmp", O_CREAT)));
    break_open();
    cr_expect(open_map("./TEST_OPEN_MAP-2.tmp", &fd));
    cr_expect_eq(fd, -1);
}
