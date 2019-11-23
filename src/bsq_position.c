/*
** EPITECH PROJECT, 2019
** <project name>
** File description:
** bsq_poisition.c -- No description
*/

#include "bsq.h"

__Aconst
bsqdata_t *bsq_position(void)
{
    static bsqdata_t bd;

    return &bd;
}
