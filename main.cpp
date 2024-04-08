#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.f};

    Character knight;
    knight.setScreenPos(windowDimensions[0], windowDimensions[1]);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // Tick
        knight.tick(GetFrameTime());

        // Check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowDimensions[0] > map.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > map.height * mapScale)
        {
            knight.undoMovement();
        }
        
        
        EndDrawing();
    }

    UnloadTexture(map);
    // UnloadTexture(knight);
    // UnloadTexture(knight_idle);
    // UnloadTexture(knight_run);
    CloseWindow();
}