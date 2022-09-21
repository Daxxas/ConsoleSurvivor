//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H

#include "../NYTimer.h"
#include "../InputHandler.h"
#include "Entity.h"

class Player : public Entity {
private:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float attacksPerSecond;
    NYTimer timer;
    InputHandler * inputHandler;
    int baseMsBetweenMovements = 250;
public:
    Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed, InputHandler* inputHandler);

    void Damage(int& damage);
	void Move(Vector2& direction);
    void Update() override;
    float GetMoveSpeed() { return moveSpeed;}
};


#endif //CONSOLESURVIVOR_PLAYER_H
