#pragma once

#include <windows.h>
#include <string>
#include "../Vector2.h"

class Entity {
public:
    Entity(Vector2& position);

    CHAR_INFO* Display();
    virtual void Update() = 0;
    bool isActive = false;
    Vector2 position;
    int spriteWidth;
    int spriteHeight;
    CHAR_INFO* sprite;
};

