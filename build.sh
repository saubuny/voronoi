#!/usr/bin/env sh

set -xe

clang -fuse-ld=mold -Wall -Wextra -Wpedantic -lraylib -o voronoi src/main.c
./voronoi
rm voronoi
ffmpeg -i output.ppm -f image2 output.png
rm output.ppm
