//
// Created by Jacques on 20/09/2022.
//

#include <string>
#include "../Vector2.h"
#include "Entity.h"
#include "Player.h"

Player::Player(Vector2 position, int maxHealth, int health, int damage) : Entity(position) {
    this->maxHealth = maxHealth;
    this->health = health;
    this->damage = damage;
}

void Player::Damage (int damage) {

}