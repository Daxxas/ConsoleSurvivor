//
// Created by Jacques on 20/09/2022.
//

#include <string>
#include "../Vector2.h"
#include "Entity.h"
#include "Player.h"

Player::Player(Vector2 position, int maxHealth, int damage) : Entity(position) {
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
}


void Player::Damage (int damage) {

}

std::string *Player::Display() {
    return nullptr;
}

Vector2 Player::GetPosition() {
    return Vector2(0, 0);
}

void Player::SetPosition(Vector2 position) {

}