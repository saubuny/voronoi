#!/usr/bin/env sh

set -xe

clang -fuse-ld=mold -Wall -Wextra -Wpedantic -lraylib -o voronoi src/main.c
