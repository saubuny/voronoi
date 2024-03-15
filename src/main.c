#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define POINT_COUNT 20
#define MODE 0

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
    const int width = 1920;
    const int height = 1080;

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
            int distance = 0;
            for (int k = 0; k < POINT_COUNT; k++) {
                if (MODE == 0) {
                    distance = ((points[k].x - x) * (points[k].x - x)) +
                               ((points[k].y - y) * (points[k].y - y));
                } else if (MODE == 1) {
                    distance = abs(points[k].x - x) + abs(points[k].y - y);
                }
                if (distance < minDistance) {
                    minDistance = distance;
                    closestPoint = points[k];
                }
            }

            // Printing the points is too hard so I'm not doing that
            fprintf(stream, "%d %d %d\n", closestPoint.color.r,
                    closestPoint.color.g, closestPoint.color.b);
        }
    }

    fclose(stream);
    return 0;
}
