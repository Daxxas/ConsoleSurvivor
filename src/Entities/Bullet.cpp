//
// Created by Jacques on 21/09/2022.
//

#include "Bullet.h"

Bullet::Bullet(Vector2& position, Vector2& direction, int damage, float speed) : Entity(position), direction(direction) {
    this->damage = damage;
    this->speed = speed;
}

void Bullet::Update() {

}

void Bullet::Move(Vector2& direction) {

}

void Bullet::Reset() {
    this->position = Vector2(0, 0);
    this->direction = Vector2(0, 0);
    isActive = false;
};