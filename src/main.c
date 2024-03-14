#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define POINT_COUNT 10

typedef struct {
    int x;
    int y;
} Position;

void generatePoints(Position points[], int max_x, int max_y) {
    for (int i = 0; i < POINT_COUNT; i++) {
        points[i].x = random() % max_x;
        points[i].y = random() % max_y;
    }
}

int main(void) {
    const int screenWidth = 640;
    const int screenHeight = 360;

    InitWindow(screenWidth, screenHeight, "Voronoi");
    SetTargetFPS(60);

    // Generate Points
    Position points[POINT_COUNT];
    generatePoints(points, screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_Q))
            CloseWindow();
        if (IsKeyPressed(KEY_SPACE))
            generatePoints(points, screenWidth, screenHeight);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < POINT_COUNT; i++) {
            // DrawPixel(points[i].x, points[i].y, BLACK);
            DrawRectangle(points[i].x, points[i].y, 5, 5, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
