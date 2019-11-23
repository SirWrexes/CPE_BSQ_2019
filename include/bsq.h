/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Main header
*/

#ifndef BSQ_H
#define BSQ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "fox_define.h"

typedef struct {
    int fd;
    struct stat stat;
} mapstat_t;

typedef struct {
    size_t x;
    size_t y;
} mapdims_t;

typedef struct {
    mapdims_t pos;
    uint size;
} bsqdata_t;

// Store BSQ placement info
bsqdata_t *bsq_position(void) __Aconst;
#define BSQPOS (*bsq_position())

// Try opening a map.
// Returns 0 if succesful
bool open_map(str2c_t path, mapstat_t *ms) __Anonnull;

// Allocate a string and fill it with the contents of the file from ms
// Returns number of written characters or -1 in case of error
scount_t read_map(str_t *buffptr, mapstat_t *ms) __Anonnull;

// Extract the map's dimensions from the created buffer
// Returns true in case of error
bool get_dimensions(mapdims_t *md, mapstat_t *ms, str_t mapbuff) __Anonnull;

// If one of the map's dimensions is 1, find the first dot
// Returns true in case of invalid character presence
bool solve_1d(str_t mapbuff) __Anonnull;

// Allocate a matrix for the BSQ algorithm
// Returns true in case of failure
bool alloc_matrix(mapdims_t *md, uint (**mtxp)[md->y][md->x]) __Anonnull;

// Solve a BSQ matrix to and store the position of the biggest square in BSQPOS
// Returns true in case of error (forbidden character)
bool solve_matrix(mapdims_t *md, uint mtx[md->y][md->x], str2c_t buff)
__Anonnull;

#endif /* !BSQ_H */
