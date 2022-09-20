//
// Created by Jacques on 20/09/2022.
//

#include <string>
#include <stdio.h>
#include <windows.h>
#include "../Vector2.h"
#include "Entity.h"
#include "Player.h"

Player::Player(Vector2 position, int maxHealth, int damage, float attacksPerSecond) : Entity(position) {
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->attacksPerSecond = attacksPerSecond;

    spriteWidth = 3;
    spriteHeight = 2;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    memset(sprite, 0, sizeof(CHAR_INFO) * spriteWidth * spriteHeight);
    sprite[0].Char.AsciiChar = ' ';
    sprite[1].Char.AsciiChar = 'o';
    sprite[2].Char.AsciiChar = ' ';
    sprite[3].Char.AsciiChar = '-';
    sprite[4].Char.AsciiChar = 'V';
    sprite[5].Char.AsciiChar = '-';

    sprite[0].Attributes = 0x0003;
    sprite[1].Attributes = 0x0003;
    sprite[2].Attributes = 0x0003;
    sprite[3].Attributes = 0x0003;
    sprite[4].Attributes = 0x0003;
    sprite[5].Attributes = 0x0003;

}


void Player::Damage (int damage) {

}

CHAR_INFO* Player::Display() {
    return sprite;
}

Vector2 Player::GetPosition() {
    return Vector2(0, 0);
}

void Player::SetPosition(Vector2 position) {

}