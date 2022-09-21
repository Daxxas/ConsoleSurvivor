//
// Created by Jacques on 21/09/2022.
//

#include "Bullet.h"

Bullet::Bullet(Vector2& position, Vector2& direction, int damage, float speed) : Entity(position), direction(direction) {
    this->damage = damage;
    this->speed = speed;

    spriteWidth = 1;
    spriteHeight = 1;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    sprite[0].Char.AsciiChar = '*';
    sprite[0].Attributes = 0x0006;
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