#pragma once

#include <windows.h>
#include <string>
#include "../Vector2.h"

class Entity {
public:
    Entity(Vector2& position);

    virtual CHAR_INFO* Display() = 0;
    virtual void Update() = 0;
    virtual void Move(Vector2&) = 0;
    bool isActive = false;
    Vector2 position;
    int spriteWidth;
    int spriteHeight;
    CHAR_INFO* sprite;
};

