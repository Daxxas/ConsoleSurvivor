#include "BasicShooter.h"

void BasicShooter::Shoot() {
    Bullet* bullet = GetBullet();
    bullet->direction = GameManager::Instance()->player->lastHeadingDirection;
    bullet->position = Vector2(0, 0);
}

Bullet * BasicShooter::CreateBullet() {
    Vector2 *dir =  new Vector2(0, 0);
    Bullet *bullet = new Bullet(*GameManager::Instance()->GetPlayerPosition(), *dir, 1, 0);
    bullet->isActive = true;
    GameManager::Instance()->AddEntity(bullet);

    return bullet;
}