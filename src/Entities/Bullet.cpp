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
    sprite[0].Char.UnicodeChar = '*';
    sprite[0].Attributes = 0x0006;

    timer.start();
}

void Bullet::Update() {
    if (timer.getElapsedMs(false) > baseMsBetweenMovements) {
        direction.normalize();		
        this->Move(direction);

        this->timer.getElapsedMs(true);
    }

    for (int i = 0; i < GameManager::Instance()->aliveEnemiesCount; i++) {
        Creature *enemy = GameManager::Instance()->enemies[i];
        if (enemy->isActive) {
            if (enemy->position == position) {
                enemy->TakeDamage(this->damage);
                isActive = false;
            }
        }
    }

	if (position.x < 0 
        || position.x > GameManager::Instance()->ARENA_WIDTH 
        || position.y < 0 
        || position.y > GameManager::Instance()->ARENA_HEIGHT) {
		isActive = false;
	}

}

void Bullet::Move(Vector2& direction) {
    Vector2 directionBoostedHorizontal = direction;
    directionBoostedHorizontal.x *= Entity::horizontalSpeedBooster;
    position = position.add(directionBoostedHorizontal);
}

void Bullet::Reset() {
    this->position = Vector2(0, 0);
    this->direction = Vector2(0, 0);
    isActive = false;
};