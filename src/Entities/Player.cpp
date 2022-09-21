#include "Player.h"

Player::Player(Vector2& position, int maxHealth, int damage, float attacksPerSecond, float moveSpeed, InputHandler * inputHandler) : Entity(position) {
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->shootSpeed = attacksPerSecond;
    this->moveSpeed = moveSpeed;
    this->inputHandler = inputHandler;

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

    moveTimer.start();
    shootTimer.start();
}

void Player::Update() {
    Vector2* direction = this->inputHandler->DetectMovementDirectionFromPlayer();

    if (moveTimer.getElapsedMs(false) > baseMsBetweenMovements/moveSpeed) {
        if (direction->x != 0 || direction->y != 0) {
            Move(*direction);
            this->moveTimer.getElapsedMs(true);
        }
    }

    if(shootTimer.getElapsedMs(false) > baseMsBetweenShoots / GetShootSpeed()) {
        Shoot();
        this->shootTimer.getElapsedMs(true);
    }
}

void Player::Shoot() {

}

Bullet* Player::GetBullet() {
    if(bullets.empty()) {
        Bullet* bullet = new Bullet(position, Vector2(0, 0), 0, 0);
        GameManager::Instance().AddEntity(bullet);

        return bullet;
    }
    else {
        Bullet* bullet = bullets.front();
        bullets.pop_front();
        return bullet;
    }
}

void Player::ReturnBullet(Bullet* bullet) {
    bullet->Reset();
    bullets.push_back(bullet);
}

void Player::Damage (int& damage) {

}

void Player::Move(Vector2& direction) {
    if (checkIfMoveIsAllowed(direction)) {
    Vector2 directionBoostedHorizontal = direction;
    directionBoostedHorizontal.x *= Entity::horizontalSpeedBooster;
	position = position.add(directionBoostedHorizontal);
    }
}

bool Player::checkIfMoveIsAllowed(Vector2& direction) {
	// Checks if x is out of bounds
    if (position.x + direction.x < (0 + GameManager::xOffset)
        || position.x + direction.x > GameManager::ARENA_WIDTH - 4) {
        return false;
    }

    // Checks if y is out of bounds
    if (position.y + direction.y < (0 + GameManager::yOffset) 
        || position.y + direction.y > GameManager::ARENA_HEIGHT - 3) {
        return false;
    }
	
    return true;
}
