#pragma once

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H

#include "../NYTimer.h"
#include "../InputHandler.h"
#include "../GameManager.h"
#include <iostream>
#include <list>
#include "Creature.h"
#include "Entity.h"
#include "../Shooters/Shooter.h"
#include "../Shooters/BasicShooter.h"

class Player : public Creature {
private:
    NYTimer shootTimer;
    InputHandler * inputHandler;
    int baseMsBetweenMovements = 150;
    int baseMsBetweenShoots = 500;
    static const int shootersCount = 1;
    Shooter* shooters[shootersCount];
    void Shoot();
public:
    Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed, InputHandler* inputHandler);
    void Damage(int& damage);
	void Move(Vector2& direction);
    bool checkIfMoveIsAllowed(Vector2& direction);
    void Update();
	void TakeDamage(int damage) override;
    void Die() override;
    float& GetMoveSpeed() { return moveSpeed; }
    float& GetShootSpeed() { return shootSpeed; }
    Vector2& GetPosition() { return position; }
    Vector2 lastHeadingDirection;
// XP
    float shootSpeed;
    int xp;
    int maxXP;
    int level = 1;
    bool playerLeveledUp = false;
    void GiveXP(int xp);
private:
    void LevelUp();
    const int baseMaxXP = 5;
};


#endif
