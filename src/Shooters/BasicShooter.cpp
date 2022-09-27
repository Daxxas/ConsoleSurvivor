#include "BasicShooter.h"
#include "../GameManager.h"

void BasicShooter::Shoot() {
    Bullet* bullet = GetBullet();
    bullet->direction = GameManager::Instance()->player->lastHeadingDirection;
    bullet->position = *GameManager::Instance()->GetPlayerPosition();
}

Bullet * BasicShooter::CreateBullet() {
    Vector2 *dir =  new Vector2(0, 0);
    Bullet *bullet = new Bullet(this, *GameManager::Instance()->GetPlayerPosition(), *dir, 1, 0);
    GameManager::Instance()->AddEntity(bullet);

    return bullet;
}