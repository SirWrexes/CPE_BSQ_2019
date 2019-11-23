/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_map_def.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

const char UTMAP_10_1_INVALIDCHAR[13] =
    "1\n"
    "ooo......T\n";

const char UTMAP_10_1_D20[13] =
    "1\n"
    "ooo.......\n";

const char S_UTMAP_10_1_D20[13] =
    "1\n"
    "ooox......\n";

const char UTMAP_1_10_D20[23] =
    "10\n"
    ".\n"
    ".\n"
    ".\n"
    ".\n"
    "o\n"
    ".\n"
    "o\n"
    ".\n"
    ".\n"
    "o\n";

const char S_UTMAP_1_10_D20[23] =
    "10\n"
    "x\n"
    ".\n"
    ".\n"
    ".\n"
    "o\n"
    ".\n"
    "o\n"
    ".\n"
    ".\n"
    "o\n";

const char UTMAP_1_10_FULL[23] =
    "10\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n"
    "o\n";

const char UTMAP_10_10_D3[113] =
    "10\n"
    "...o..o...\n"
    "o.........\n"
    "......o.o.\n"
    ".....o.o.o\n"
    "..o.o....o\n"
    "..........\n"
    "......oo.o\n"
    ".......o..\n"
    "o.o.o..o..\n"
    "....o.....\n";

const char UTMAP_10_10_D3_INVALIDL1_A[116] =
    "   10\n"
    "...o..o...\n"
    "o.........\n"
    "......o.o.\n"
    ".....o.o.o\n"
    "..o.o....o\n"
    "..........\n"
    "......oo.o\n"
    ".......o..\n"
    "o.o.o..o..\n"
    "....o.....\n";

const char UTMAP_10_10_D3_INVALIDL1_B[116] =
    "10   \n"
    "...o..o...\n"
    "o.........\n"
    "......o.o.\n"
    ".....o.o.o\n"
    "..o.o....o\n"
    "..........\n"
    "......oo.o\n"
    ".......o..\n"
    "o.o.o..o..\n"
    "....o.....\n";

const char UTMAP_10_10_D3_INVALIDCC[110] =
    "10\n"
    "...o..o...\n"
    "o.........\n"
    "......o.o.\n"
    ".....o.o.o\n"
    "..o.o..\n"
    "..........\n"
    "......oo.o\n"
    ".......o..\n"
    "o.o.o..o..\n"
    "....o.....\n";

const char UTMAP_6_6_INVALIDCHAR[44] =
    "6\n"
    ".o.o..\n"
    "o...o.\n"
    ".o....\n"
    "...O..\n"
    "....o.\n"
    ".o....\n";

const char UTMAP_6_6_D25[44] =
    "6\n"
    ".ooo..\n"
    ".....o\n"
    "o.o..o\n"
    "o.o..o\n"
    "o.o...\n"
    "...o.o\n";

const uint UTMTX_6_6_D25[6][6] = {
    {1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 2, 0},
    {0, 1, 0, 1, 2, 0},
    {0, 1, 0, 1, 2, 1},
    {1, 1, 1, 0, 1, 0},
};
