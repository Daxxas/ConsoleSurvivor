#pragma once
#ifndef CONSOLESURVIVOR_CREATURE_H
#define CONSOLESURVIVOR_CREATURE_H

#include "../NYTimer.h"
#include <iostream>
#include <list>
#include "Entity.h"

class Creature : public Entity {
protected:
    int maxHealth;
    int health;
    int damage;
    NYTimer moveTimer;
    int baseMsBetweenMovements;
public:
    float moveSpeed;
    float shootSpeed;
    Creature();
    Creature(Vector2& position);
    Creature(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);
    bool checkIfMoveIsAllowed(Vector2& direction);
    void Update() {};
    float& GetMoveSpeed() { return moveSpeed; }
    Vector2& GetPosition() { return position; }
};


#endif
