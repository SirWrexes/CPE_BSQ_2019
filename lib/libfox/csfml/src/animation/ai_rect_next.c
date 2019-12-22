/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** anim_current_rect.c -- No description
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext const sfIntRect *ai_rect_next(animinfo_t ai)
{
    return &ai_meta(ai)->rect[ai->frame + 1];
}
