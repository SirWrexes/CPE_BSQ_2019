##
## EPITECH PROJECT, 2019
## Multipart Makefile
## File description:
## Project/binary name and sources
##

#
# Project and binary name
################################################
NAME := BSQ
BIN  := bsq
#     It's IMPORTANT that the binary name
# /!\ contains no whitespace !
#     Otherwise it'l break the Progress% script.
################################################

#
# Sources
################################################
MAIN := ./src/main.c
# -------------------------------------------- #
SRC := ./src/open_map.c
SRC += ./src/read_map.c
SRC += ./src/get_dimensions.c
SRC += ./src/solve_1d.c
SRC += ./src/alloc_matrix.c
################################################

#
# Test sources
################################################
TST := ./tests/test_maps_def.c
TST += ./tests/test_open_map.c
TST += ./tests/test_read_map.c
TST += ./tests/test_get_dimensions.c
TST += ./tests/test_solve_1d.c
TST += ./tests/test_alloc_matrix.c
################################################


#
# Files created by unit tests functions
################################################
TESTTMP := TEST_OPEN_MAP-1.tmp
TESTTMP += TEST_OPEN_MAP-2.tmp
TESTTMP += UTMAP_10_10_D3-dimensions-OK.tmp
TESTTMP += UTMAP_10_10_D3-invalid_cc.tmp
TESTTMP += UTMAP_10_10_D3-invalid_l1-A.tmp
TESTTMP += UTMAP_10_10_D3-invalid_l1-B.tmp
TESTTMP += UTMAP_10_10_D3-no_malloc.tmp
TESTTMP += UTMAP_10_10_D3-no_malloc.tmp
TESTTMP += UTMAP_10_10_D3.tmp
TESTTMP += UTMAP_6_6_D25-alloctest.tmp
TESTTMP += UTMAP_6_6_D25-alloctest_fail.tmp
################################################

#
# Libs to include
################################################
LIBS :=
LIBS +=
################################################

#
# Comment or uncomment the lines corresponding
# to the libfox modules you use in the project.
################################################
# FOXMODULES += datastruct
FOXMODULES += io
FOXMODULES += math
FOXMODULES += std
FOXMODULES += string
################################################
