/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ maps for unit tests
*/

#ifndef MAPS_H
#define MAPS_H

#include "fox_define.h"

extern const char UTMAP_10_10_D3[113];
extern const char UTMAP_10_10_D3_INVALIDL1_A[116];
extern const char UTMAP_10_10_D3_INVALIDL1_B[116];
extern const char UTMAP_10_10_D3_INVALIDCC[110];

#define ASSERT_FWRITE_MAP(mapname, fp)                                 \
    cr_assert_eq(                                                      \
        fwrite((mapname), sizeof(*(mapname)), sizeof((mapname)), (fp)) \
        + fclose((fp)),                                                \
        sizeof((mapname)) / sizeof((*mapname)))

#endif /* !MAPS_H */
