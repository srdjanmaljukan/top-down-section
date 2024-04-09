#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

int main()
{
    int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.f};

    Character knight{windowDimensions[0], windowDimensions[1]};

    Prop props[2]{
        Prop{LoadTexture("nature_tileset/Rock.png"), Vector2{600.f, 300.f}},
        Prop{LoadTexture("nature_tileset/Log.png"), Vector2{400.f, 500.f}}};

    Enemy goblin{
        Vector2{0.f, 0.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};
    
    goblin.setTarget(&knight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // Draw props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }

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

        // Check collision with props
        for (auto prop : props)
        {
            if (CheckCollisionRecs(knight.getCollisionRec(), prop.getCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        goblin.tick(GetFrameTime());

        EndDrawing();
    }

    UnloadTexture(map);
    // UnloadTexture(knight);
    // UnloadTexture(knight_idle);
    // UnloadTexture(knight_run);
    CloseWindow();
}