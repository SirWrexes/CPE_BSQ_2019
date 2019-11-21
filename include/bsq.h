/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Main header
*/

#ifndef BSQ_H
#define BSQ_H

#include <stdbool.h>
#include "fox_define.h"

// Try opening a map.
// Returns 0 if succesful
bool open_map(str2c_t path, int *fd) __nonnull;

#endif /* !BSQ_H */
