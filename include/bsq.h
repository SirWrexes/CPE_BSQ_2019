/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Main header
*/

#ifndef BSQ_H
#define BSQ_H

#include <sys/stat.h>
#include <stdbool.h>

#include "fox_define.h"

typedef struct {
    int fd;
    struct stat stat;
} mapstat_t;

// Try opening a map.
// Returns 0 if succesful
bool open_map(str2c_t path, mapstat_t *ms) __Anonnull;

#endif /* !BSQ_H */
