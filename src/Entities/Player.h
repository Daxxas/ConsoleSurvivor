#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H

#include "Entity.h"

class Player : public Entity {
private:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float attacksPerSecond;
public:
    Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);

    void Damage(int& damage);
	void Move(Vector2& direction);
    CHAR_INFO* Display() override;
    void Update() override;
    float& GetMoveSpeed() { return moveSpeed;}
    Vector2& GetPosition() { return position; }
};


#endif
