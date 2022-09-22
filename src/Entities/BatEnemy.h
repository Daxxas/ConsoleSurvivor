#pragma once

#include "Creature.h"
#include "../GameManager.h"

class BatEnemy : public Creature {
public:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float attacksPerSecond;
    NYTimer timer;
    int baseMsBetweenMovements = 250;
public:
    BatEnemy(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);
    void Update() override;
    void TakeDamage(int) override;
    void Die() override;
    void Move(Vector2&) override;

};