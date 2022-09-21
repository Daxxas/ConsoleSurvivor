#include "BatEnemy.h"

BatEnemy::BatEnemy(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed) : Entity(position) {

    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->attacksPerSecond = attacksPerSecond;
    this->moveSpeed = moveSpeed;
	
    spriteWidth = 3;
    spriteHeight = 1;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    memset(sprite, 0, sizeof(CHAR_INFO) * spriteWidth * spriteHeight);
    sprite[0].Char.AsciiChar = '>';
    sprite[1].Char.AsciiChar = 'o';
    sprite[2].Char.AsciiChar = '<';

    sprite[0].Attributes = 0x0006;
    sprite[1].Attributes = 0x0006;
    sprite[2].Attributes = 0x0006;

    timer.start();
}

void BatEnemy::Update() {
    if (timer.getElapsedMs(false) > baseMsBetweenMovements / moveSpeed) {
        Vector2 playerPosition = *GameManager::Instance().GetPlayerPosition();
        Vector2 directionToFollow = playerPosition - this->position;
		
        directionToFollow.normalize();
        this->Move(directionToFollow);
		
        this->timer.getElapsedMs(true);
    }
}

void BatEnemy::Move(Vector2& direction) {
    Vector2 directionBoostedHorizontal = direction;
    directionBoostedHorizontal.x *= Entity::horizontalSpeedBooster;
    position = position.add(directionBoostedHorizontal);
}