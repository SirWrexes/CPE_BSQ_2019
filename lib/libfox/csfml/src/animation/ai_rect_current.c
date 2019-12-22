/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the current animation rectangle
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext const sfIntRect *ai_rect_current(animinfo_t ai)
{
    return &ai_meta(ai)->rect[ai->frame];
}
