/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** ai_current_type.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext unsigned ai_type(animinfo_t ai)
{
    return ai_meta(ai)->type;
}
