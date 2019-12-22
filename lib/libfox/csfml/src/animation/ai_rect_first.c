/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Get the address of current animation's first rectangle
*/

#include "fox_csfml.h"

__Anonnull __AalwaysILext const sfIntRect *ai_rect_first(animinfo_t ai)
{
    return &ai_meta(ai)->rect[0];
}
