/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ maps for unit tests
*/

#ifndef MAPS_H
#define MAPS_H

#include <sys/types.h>
#include "fox_define.h"

// Maps (UTMAP_[Y]_[X]_[DENSITY/ERROR])
/* Trigger an error */
extern const char UTMAP_10_10_D3_INVALIDCC[110];
extern const char UTMAP_10_10_D3_INVALIDL1_A[116];
extern const char UTMAP_10_10_D3_INVALIDL1_B[116];
extern const char UTMAP_10_1_INVALIDCHAR[13];
/* Work fine       */
extern const char UTMAP_10_10_D3[113];
extern const char UTMAP_10_1_D20[13];
extern const char UTMAP_1_10_D20[23];
extern const char UTMAP_1_10_FULL[23];

// Solved maps
extern const char S_UTMAP_10_1_D20[13];
extern const char S_UTMAP_1_10_D20[23];

// Matrix converted maps
extern const uint UTMATRIX_10_10_D3[113];

#define ASSERT_FWRITE_MAP(mapname, fp)                                 \
    cr_assert_eq(                                                      \
        fwrite((mapname), sizeof(*(mapname)), sizeof((mapname)), (fp)) \
        + fclose((fp)),                                                \
        sizeof((mapname)) / sizeof((*mapname)))

#endif /* !MAPS_H */
