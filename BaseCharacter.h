#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    float width{};
    float height{};
    float speed{4.f};
    Vector2 worldPosLastFrame{};
    float scale{4.f};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // Animation variables
    float runningTime{};
    int frame{};
    int maxFrame{6};
    float updateTime{1.f / 12.f};
};

#endif