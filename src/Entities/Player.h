#pragma once

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H

#include "../NYTimer.h"
#include "../InputHandler.h"
#include "../GameManager.h"
#include <iostream>
#include <list>
#include "Bullet.h"
#include "Creature.h"
#include "Entity.h"

class Bullet;

class Player : public Creature {
private:
    float shootSpeed;
    NYTimer shootTimer;
    InputHandler * inputHandler;
    int baseMsBetweenMovements = 150;
    int baseMsBetweenShoots = 500;
    Vector2 lastHeadingDirection;
    void Shoot();
    void LevelUp();
    const int baseMaxXP = 5;
public:
    Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed, InputHandler* inputHandler);
    void Damage(int& damage);
	void Move(Vector2& direction);
    bool checkIfMoveIsAllowed(Vector2& direction);
    void Update();
	void TakeDamage(int damage) override;
    void Die() override;
    float& GetMoveSpeed() { return moveSpeed;}
    float& GetShootSpeed() { return shootSpeed;}
    Vector2& GetPosition() { return position; }
    int xp;
    int maxXP;
    int level = 1;
    bool playerLeveledUp = false;
    void GiveXP(int xp);
// Bullet management
public:
    std::list<Bullet*> bullets;
    Bullet* GetBullet();
    void ReturnBullet(Bullet* bullet);
private:
    int lastBulletIndex = 0;
};


#endif
