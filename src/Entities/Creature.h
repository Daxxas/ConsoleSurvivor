#ifndef CONSOLESURVIVOR_CREATURE_H
#define CONSOLESURVIVOR_CREATURE_H

#include "../NYTimer.h"
#include <iostream>
#include <list>
#include "Bullet.h"
#include "Entity.h"

class Bullet;

class Creature : public Entity {
private:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float shootSpeed;
    NYTimer moveTimer;
    int baseMsBetweenMovements;
public:
    Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed, InputHandler* inputHandler);
    void Damage(int& damage);
    bool checkIfMoveIsAllowed(Vector2& direction);
    float& GetMoveSpeed() { return moveSpeed; }
    Vector2& GetPosition() { return position; }
};


#endif
