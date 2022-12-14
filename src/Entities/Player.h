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
#include "../Shooters/VerticalShooter.h"
#include "../Shooters/HorizontalShooter.h"
#include "../Shooters/MineShooter.h"


class Player : public Creature {
private:
    NYTimer shootTimer;
    InputHandler * inputHandler;
    int baseMsBetweenMovements = 150;
    static const int shootersCount = 4;
    void Shoot();
public:
    bool isDead = false;
    Player(Vector2& position, int maxHealth, int damage, float moveSpeed, InputHandler* inputHandler);
    Shooter* shooters[shootersCount];
    void Damage(int& damage);
	void Move(Vector2& direction);
    bool checkIfMoveIsAllowed(Vector2& direction);
    void Update();
	void TakeDamage(int damage) override;
    void Die() override;
    Vector2& GetPosition() { return position; }
    Vector2 lastHeadingDirection;
// XP
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
