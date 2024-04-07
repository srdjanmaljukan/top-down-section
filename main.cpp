#include "raylib.h"

int main()
{
    int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
}