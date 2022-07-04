#!/bin/sh
CC=cc
PRG=saccalc
set -e
set -x
$CC -Wall -static -O3 -ansi -pedantic -o $PRG $PRG.c -lm
