//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_ENTITY_H
#define CONSOLESURVIVOR_ENTITY_H

#include <windows.h>
#include "../Vector2.h"
#include <string>


class Entity {
public:
    Entity(Vector2 position);

    virtual CHAR_INFO* Display() = 0;
    virtual Vector2 GetPosition() = 0;
    virtual void SetPosition(Vector2 position) = 0;
    bool isActive = false;
    Vector2 position;
    int spriteWidth;
    int spriteHeight;
};


#endif //CONSOLESURVIVOR_ENTITY_H
