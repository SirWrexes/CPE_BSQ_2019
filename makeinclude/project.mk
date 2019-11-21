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
SRC +=
################################################

#
# Test sources
################################################
TST := ./tests/test_open_map.c
TST +=
################################################


#
# Files created by unit tests functions
################################################
TESTTMP := TEST_OPEN_MAP-1.tmp
TESTTMP += TEST_OPEN_MAP-2.tmp
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
# FOXMODULES += io
# FOXMODULES += std
# FOXMODULES += string
################################################
