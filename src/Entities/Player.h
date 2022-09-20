//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_PLAYER_H
#define CONSOLESURVIVOR_PLAYER_H


class Player : Entity {
public:
    Player(Vector2 position, int maxHealth, int damage);

    void Damage(int damage);
    void SetPosition(Vector2 position) override;
    Vector2 GetPosition() override;
    std::string* Display() override;
private:
    int maxHealth;
    int health;
    int damage;
};


#endif //CONSOLESURVIVOR_PLAYER_H
