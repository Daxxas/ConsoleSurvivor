#include "BatEnemy.h"

BatEnemy::BatEnemy(Vector2 position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed) : Creature(position) {

    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->attacksPerSecond = attacksPerSecond;
    this->moveSpeed = moveSpeed;
	
    spriteWidth = 3;
    spriteHeight = 1;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    memset(sprite, 0, sizeof(CHAR_INFO) * spriteWidth * spriteHeight);
    sprite[0].Char.UnicodeChar = '>';
    sprite[1].Char.UnicodeChar = 'o';
    sprite[2].Char.UnicodeChar = '<';

    sprite[0].Attributes = 0x0006;
    sprite[1].Attributes = 0x0006;
    sprite[2].Attributes = 0x0006;

    timer.start();
}

void BatEnemy::Update() {
    if (timer.getElapsedMs(false) > baseMsBetweenMovements / moveSpeed) {
        Vector2 playerPosition = *GameManager::Instance()->GetPlayerPosition();
        Vector2 directionToFollow = playerPosition - this->position;
		
        directionToFollow.normalize();
        this->Move(directionToFollow);
		
        this->timer.getElapsedMs(true);
    }

	Vector2 playerPosition = *GameManager::Instance()->GetPlayerPosition();
    if (playerPosition.x <= position.x + spriteWidth && playerPosition.x >= position.x) {
        if (playerPosition.y <= position.y + spriteHeight && playerPosition.y >= position.y) {
            GameManager::Instance()->player->TakeDamage(1);
        }
    }
}

void BatEnemy::TakeDamage(int dmg) {
	this->health -= dmg;
	if (this->health <= 0) {
        Die();
	}
}

void BatEnemy::Die() {
    GameManager::Instance()->player->GiveXP(1);
    isActive = false;
    // TODO
}


void BatEnemy::Move(Vector2& direction) {
    Vector2 directionBoostedHorizontal = direction;
    directionBoostedHorizontal.x *= Entity::horizontalSpeedBooster;
    position = position.add(directionBoostedHorizontal);
}