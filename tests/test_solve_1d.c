/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_solve_1d.c -- No description
*/

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

#include "bsq.h"

Test(solve_1d, y_eq_1, .init = cr_redirect_stdout)
{
    str_t buff = strdup(UTMAP_1_10_D20);

    cr_expect_not(solve_1d(buff));
    cr_expect_stdout_eq_str(S_UTMAP_1_10_D20 + 3);
    free(buff);
}

Test(solve_1d, x_eq_1, .init = cr_redirect_stdout)
{
    str_t buff = strdup(UTMAP_10_1_D20);

    cr_expect_not(solve_1d(buff));
    cr_expect_stdout_eq_str(S_UTMAP_10_1_D20 + 2);
    free(buff);
}

Test(solve_1d, invalid_character, .init = cr_redirect_stdout)
{
    str_t buff = strdup(UTMAP_10_1_INVALIDCHAR);

    cr_expect(solve_1d(buff));
    free(buff);
}
