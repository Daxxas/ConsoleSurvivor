#pragma once

#include <windows.h>
#include <string>
#include "../Vector2.h"

class Entity {
public:
    Entity(Vector2& position);

    static const int horizontalSpeedBooster = 2;
		
    CHAR_INFO* Display();
    virtual void Update() {};
    virtual void Move(Vector2&) = 0;
    bool isActive = false;
    Vector2 position;
    int spriteWidth;
    int spriteHeight;
    CHAR_INFO* sprite;

    int GetSpriteWidth() { return spriteWidth; }
    int GetSpriteHeight() { return spriteHeight; }
};
