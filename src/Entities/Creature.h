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
    float moveSpeed;
    float shootSpeed;
    NYTimer moveTimer;
    int baseMsBetweenMovements;
public:
    Creature();
    Creature(Vector2& position);
    Creature(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);
    bool checkIfMoveIsAllowed(Vector2& direction);
    void Update() {};
    virtual void TakeDamage(int)=0;
    virtual void Die()=0;
    float& GetMoveSpeed() { return moveSpeed; }
    Vector2& GetPosition() { return position; }
};


#endif
