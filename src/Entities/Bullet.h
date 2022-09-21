#pragma once
#ifndef CONSOLESURVIVOR_BULLET_H
#define CONSOLESURVIVOR_BULLET_H

#include "Entity.h"

class Bullet : public Entity {
private:
    Vector2& direction;
    int damage;
    float speed;
public:
    Bullet(Vector2& position, Vector2& direction, int damage, float speed);
    void Update() override;
};


#endif //CONSOLESURVIVOR_BULLET_H
