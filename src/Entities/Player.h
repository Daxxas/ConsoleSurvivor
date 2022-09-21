//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H


class Player : public Entity {
public:
    Player(Vector2 position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);

    void Damage(int damage);
	void Move(Vector2 direction);
    CHAR_INFO* Display() override;
    void Update() override;
private:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float attacksPerSecond;
};


#endif //CONSOLESURVIVOR_PLAYER_H
