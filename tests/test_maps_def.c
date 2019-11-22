/*
** EPITECH PROJECT, 2019
** <project name> unit tests
** File description:
** test_map_def.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/maps.h"

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
