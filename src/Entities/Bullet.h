#pragma once
#ifndef CONSOLESURVIVOR_BULLET_H
#define CONSOLESURVIVOR_BULLET_H

#include "../NYTimer.h"
#include "Entity.h"
#include "../GameManager.h"

class Bullet : public Entity {
private:
    int damage;
    float speed;
    NYTimer timer;
    int baseMsBetweenMovements = 50;
public:
    Vector2& direction;
    Bullet(Vector2& position, Vector2& direction, int damage, float speed);
    void Update() override;
    void Move(Vector2&) override;
    void Reset();
};


#endif //CONSOLESURVIVOR_BULLET_H
