//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H


class Player : public Entity {
public:
    Player(Vector2 position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed);

    void Damage(int damage);
    void SetPosition(Vector2 position) override;
	void Move(Vector2 direction);
    Vector2 GetPosition() override;
    CHAR_INFO* Display() override;
private:
    int maxHealth;
    int health;
    int damage;
    float moveSpeed;
    float attacksPerSecond;
    CHAR_INFO* sprite;
};


#endif //CONSOLESURVIVOR_PLAYER_H
