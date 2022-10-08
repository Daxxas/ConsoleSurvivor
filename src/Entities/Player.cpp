#include "Player.h"

Player::Player(Vector2& position, int maxHealth, int damage, float moveSpeed, InputHandler * inputHandler) : Creature(position) {
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->damage = damage;
    this->moveSpeed = moveSpeed;
    this->inputHandler = inputHandler;
    this->lastHeadingDirection = Vector2(1, 0);
    level = 1;
    this->xp = 0;
    this->maxXP = baseMaxXP;
    spriteWidth = 3;
    spriteHeight = 2;

    sprite = new CHAR_INFO[spriteWidth * spriteHeight];
    memset(sprite, 0, sizeof(CHAR_INFO) * spriteWidth * spriteHeight);
    sprite[0].Char.UnicodeChar = ' ';
    sprite[1].Char.UnicodeChar = 'o';
    sprite[2].Char.UnicodeChar = ' ';
    sprite[3].Char.UnicodeChar = '-';
    sprite[4].Char.UnicodeChar = 'V';
    sprite[5].Char.UnicodeChar = '-';

    sprite[0].Attributes = 0x0003;
    sprite[1].Attributes = 0x0003;
    sprite[2].Attributes = 0x0003;
    sprite[3].Attributes = 0x0003;
    sprite[4].Attributes = 0x0003;
    sprite[5].Attributes = 0x0003;

    shooters[0] = new BasicShooter();
    shooters[1] = new HorizontalShooter();
    shooters[2] = new VerticalShooter();
    shooters[3] = new MineShooter();

    moveTimer.start();
    shootTimer.start();
}

void Player::Update() {
    Vector2 direction = this->inputHandler->DetectMovementDirectionFromPlayer();

    if (moveTimer.getElapsedMs(false) > baseMsBetweenMovements/moveSpeed) {
        if (direction.x != 0 || direction.y != 0) {
            Move(direction);
            // Debug, todo : remove
            GiveXP(1);
            this->moveTimer.getElapsedMs(true);
        }
    }

    Shoot();
}

void Player::GiveXP(int xp) {
    this->xp += xp;
    if (this->xp >= this->maxXP) {
        LevelUp();
    }
}

void Player::LevelUp() {
    level++;
    int increaseByLevel;

    if(level <= 20) {
        increaseByLevel = 10;
    }
    else if (level <= 40) {
        increaseByLevel = 13;
    }
    else {
        increaseByLevel = 16;
    }
    // Substraction in case player has more than maxXP
    xp = xp - maxXP;
    maxXP = baseMaxXP + (level-1) * increaseByLevel;
    playerLeveledUp = true;
    GameManager::Instance()->pause = true;
    // todo pause difficulty
    GameManager::Instance()->upgradeList->RefreshUpgrades();
}

void Player::Shoot() {
    for (Shooter *shooter : shooters) {
        shooter->Update();
    }
}

void Player::Damage (int& damage) {

}

void Player::Move(Vector2& direction) {
    if (checkIfMoveIsAllowed(direction)) {
        Vector2 directionBoostedHorizontal = direction;
        directionBoostedHorizontal.x *= Entity::horizontalSpeedBooster;
	    position = position.add(directionBoostedHorizontal);

        directionBoostedHorizontal.normalize();
        lastHeadingDirection = directionBoostedHorizontal;
    }
}

void Player::TakeDamage(int dmg) {
    Die();
}

void Player::Die() {
    this->isDead = true;
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
