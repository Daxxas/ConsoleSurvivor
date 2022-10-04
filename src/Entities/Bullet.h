#pragma once
#ifndef CONSOLESURVIVOR_BULLET_H
#define CONSOLESURVIVOR_BULLET_H

#include "../NYTimer.h"
#include "Entity.h"
#include "../Shooters/Shooter.h"

class Shooter;

class Creature;

class Bullet : public Entity {
private:
    int damage;
    float speed;
    NYTimer timer;
    int baseMsBetweenMovements = 50;
    Shooter* shooter;
public:
    Vector2& direction;
    Bullet(Shooter* shooter, Vector2& position, Vector2& direction, int damage, float speed);
    void Update() override;
    void Move(Vector2&) override;
    virtual void Reset();
    bool CheckIfHits(Creature&);
};


#endif //CONSOLESURVIVOR_BULLET_H
