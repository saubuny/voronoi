#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define POINT_COUNT 20

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

typedef struct {
    int x;
    int y;
    Color color;
} Position;

int main(void) {
    const int width = 1280;
    const int height = 720;

    Position points[POINT_COUNT];
    for (int i = 0; i < POINT_COUNT; i++) {
        points[i].x = random() % width;
        points[i].y = random() % height;
        points[i].color.r = random() % 255;
        points[i].color.g = random() % 255;
        points[i].color.b = random() % 255;
    }

    FILE *stream = fopen("output.ppm", "w");
    fprintf(stream, "P3\n");
    fprintf(stream, "%d %d\n", width, height);
    fprintf(stream, "255\n");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Position closestPoint;
            int minDistance = INT_MAX;
            for (int k = 0; k < POINT_COUNT; k++) {
                int distanceSquared = ((points[k].x - x) * (points[k].x - x)) +
                                      ((points[k].y - y) * (points[k].y - y));
                if (distanceSquared < minDistance) {
                    minDistance = distanceSquared;
                    closestPoint = points[k];
                }
            }
            if (closestPoint.x == x && closestPoint.y == y) {
                fprintf(stream, "0 0 0\n");
            } else {
                fprintf(stream, "%d %d %d\n", closestPoint.color.r,
                        closestPoint.color.g, closestPoint.color.b);
            }
        }
    }

    fclose(stream);
    return 0;
}
